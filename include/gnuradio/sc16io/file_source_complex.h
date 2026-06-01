#pragma once

#include <gnuradio/sc16io/api.h>
#include <gnuradio/sync_block.h>
#include <memory>
#include <string>

namespace gr {
namespace sc16io {

class SC16IO_API file_source_complex : virtual public gr::sync_block
{
public:
    using sptr = std::shared_ptr<file_source_complex>;

    static sptr make(const std::string& filename,
                     const std::string& source_type = "sc16",
                     bool repeat = false);
};

} // namespace sc16io
} // namespace gr