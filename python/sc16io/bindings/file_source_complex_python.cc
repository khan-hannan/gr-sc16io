#include <pybind11/pybind11.h>

#include <gnuradio/sc16io/file_source_complex.h>

namespace py = pybind11;

void bind_file_source_complex(py::module& m)
{
    using file_source_complex = gr::sc16io::file_source_complex;

    py::class_<file_source_complex,
               gr::sync_block,
               gr::block,
               gr::basic_block,
               std::shared_ptr<file_source_complex>>(m, "file_source_complex")
        .def(py::init(&file_source_complex::make),
             py::arg("filename"),
             py::arg("source_type") = "sc16",
             py::arg("repeat") = false);
}