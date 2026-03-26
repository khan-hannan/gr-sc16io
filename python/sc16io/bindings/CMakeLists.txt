# Copyright 2020 Free Software Foundation, Inc.
#
# This file is part of GNU Radio
#
# SPDX-License-Identifier: GPL-3.0-or-later
#

########################################################################
# Check if there is C++ code at all
########################################################################
if(NOT sc16io_sources)
    message(STATUS "No C++ sources... skipping python bindings")
    return()
endif(NOT sc16io_sources)

########################################################################
# Check for pygccxml
########################################################################
gr_python_check_module_raw("pygccxml" "import pygccxml" PYGCCXML_FOUND)

include(GrPybind)

########################################################################
# Python Bindings
########################################################################

list(APPEND sc16io_python_files
    file_source_complex_python.cc python_bindings.cc)

gr_pybind_make_oot(sc16io ../../.. gr::sc16io "${sc16io_python_files}")

# copy bindings extension for use in QA test module
add_custom_command(
    TARGET sc16io_python
    POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:sc16io_python>
            ${PROJECT_BINARY_DIR}/test_modules/gnuradio/sc16io/)

install(
    TARGETS sc16io_python
    DESTINATION ${GR_PYTHON_DIR}/gnuradio/sc16io
    COMPONENT pythonapi)
