#include "file_source_complex_impl.h"

#include <gnuradio/io_signature.h>
#include <stdexcept>

namespace gr {
namespace sc16io {

file_source_complex::sptr
file_source_complex::make(const std::string& filename,
                          const std::string& source_type,
                          bool repeat)
{
    return gnuradio::make_block_sptr<file_source_complex_impl>(
        filename, source_type, repeat);
}

std::string file_source_complex_impl::normalize_source_type(
    const std::string& source_type)
{
    if (source_type == "sc16" || source_type == "complex16" ||
        source_type == "c16") {
        return "sc16";
    }

    if (source_type == "sc8" || source_type == "complex8" ||
        source_type == "c8") {
        return "sc8";
    }

    throw std::invalid_argument(
        "file_source_complex: unsupported source_type '" + source_type +
        "'. Use 'sc16' or 'sc8'.");
}

size_t file_source_complex_impl::itemsize_from_source_type(
    const std::string& source_type)
{
    const std::string norm = normalize_source_type(source_type);

    if (norm == "sc16") {
        return 2 * sizeof(int16_t); // I,Q = 4 bytes/sample
    }

    if (norm == "sc8") {
        return 2 * sizeof(int8_t); // I,Q = 2 bytes/sample
    }

    throw std::invalid_argument("file_source_complex: invalid source_type");
}

file_source_complex_impl::file_source_complex_impl(const std::string& filename,
                                                   const std::string& source_type,
                                                   bool repeat)
    : gr::sync_block("file_source_complex",
                     gr::io_signature::make(0, 0, 0),
                     gr::io_signature::make(
                         1, 1, itemsize_from_source_type(source_type))),
      d_filename(filename),
      d_source_type(normalize_source_type(source_type)),
      d_repeat(repeat),
      d_itemsize(itemsize_from_source_type(source_type))
{
    if (!reopen()) {
        throw std::runtime_error("file_source_complex: failed to open file: " +
                                 d_filename);
    }

    set_output_multiple(1024);
}

file_source_complex_impl::~file_source_complex_impl()
{
    if (d_file.is_open()) {
        d_file.close();
    }
}

bool file_source_complex_impl::reopen()
{
    if (d_file.is_open()) {
        d_file.close();
    }

    d_file.clear();
    d_file.open(d_filename.c_str(), std::ios::binary);
    return d_file.is_open();
}

int file_source_complex_impl::work(int noutput_items,
                                   gr_vector_const_void_star& input_items,
                                   gr_vector_void_star& output_items)
{
    (void)input_items;

    auto* out = reinterpret_cast<char*>(output_items[0]);
    int produced = 0;

    while (produced < noutput_items) {
        if (!d_file.is_open()) {
            if (!reopen()) {
                return produced > 0 ? produced : WORK_DONE;
            }
        }

        const auto remaining_items = noutput_items - produced;
        const auto wanted_bytes =
            static_cast<std::streamsize>(remaining_items) *
            static_cast<std::streamsize>(d_itemsize);

        d_file.read(out + static_cast<std::ptrdiff_t>(produced) *
                              static_cast<std::ptrdiff_t>(d_itemsize),
                    wanted_bytes);

        const auto got_bytes = d_file.gcount();
        const int got_items =
            static_cast<int>(got_bytes / static_cast<std::streamsize>(d_itemsize));

        produced += got_items;

        if (produced == noutput_items) {
            return produced;
        }

        if (d_file.eof()) {
            d_file.clear();

            if (d_repeat) {
                d_file.seekg(0, std::ios::beg);
                if (!d_file.good()) {
                    return produced > 0 ? produced : WORK_DONE;
                }
                continue;
            }

            return produced > 0 ? produced : WORK_DONE;
        }

        if (d_file.fail() || d_file.bad()) {
            d_file.clear();
            return produced > 0 ? produced : WORK_DONE;
        }

        if (got_items == 0) {
            return produced > 0 ? produced : WORK_DONE;
        }
    }

    return produced;
}

} // namespace sc16io
} // namespace gr