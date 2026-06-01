#pragma once

#include <gnuradio/sc16io/file_source_complex.h>
#include <cstddef>
#include <fstream>
#include <string>

namespace gr {
namespace sc16io {

class file_source_complex_impl : public file_source_complex
{
private:
    std::string d_filename;
    std::string d_source_type;
    bool d_repeat;
    size_t d_itemsize;
    std::ifstream d_file;

    static std::string normalize_source_type(const std::string& source_type);
    static size_t itemsize_from_source_type(const std::string& source_type);
    bool reopen();

public:
    file_source_complex_impl(const std::string& filename,
                             const std::string& source_type,
                             bool repeat);
    ~file_source_complex_impl() override;

    int work(int noutput_items,
             gr_vector_const_void_star& input_items,
             gr_vector_void_star& output_items) override;
};

} // namespace sc16io
} // namespace gr