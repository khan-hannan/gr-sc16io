/* -*- c++ -*- */
/*
 * Copyright 2026 Hannan.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef INCLUDED_SC16IO_FILE_SOURCE_COMPLEX_IMPL_H
#define INCLUDED_SC16IO_FILE_SOURCE_COMPLEX_IMPL_H

#include <gnuradio/sc16io/file_source_complex.h>

namespace gr {
  namespace sc16io {

    class file_source_complex_impl : public file_source_complex
    {
     private:
      // Nothing to declare in this block.

     public:
      file_source_complex_impl(std::string filename, std::string source_type, bool repeat);
      ~file_source_complex_impl();

      // Where all the action really happens
      int work(
              int noutput_items,
              gr_vector_const_void_star &input_items,
              gr_vector_void_star &output_items
      );
    };

  } // namespace sc16io
} // namespace gr

#endif /* INCLUDED_SC16IO_FILE_SOURCE_COMPLEX_IMPL_H */
