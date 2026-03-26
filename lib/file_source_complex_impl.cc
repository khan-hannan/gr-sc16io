/* -*- c++ -*- */
/*
 * Copyright 2026 Hannan.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include <gnuradio/io_signature.h>
#include "file_source_complex_impl.h"

namespace gr {
  namespace sc16io {

    #pragma message("set the following appropriately and remove this warning")
    using output_type = float;
    file_source_complex::sptr
    file_source_complex::make(std::string filename, std::string source_type, bool repeat)
    {
      return gnuradio::make_block_sptr<file_source_complex_impl>(
        filename, source_type, repeat);
    }


    /*
     * The private constructor
     */
    file_source_complex_impl::file_source_complex_impl(std::string filename, std::string source_type, bool repeat)
      : gr::sync_block("file_source_complex",
              gr::io_signature::make(0, 0, 0),
              gr::io_signature::make(1 /* min outputs */, 1 /*max outputs */, sizeof(output_type)))
    {}

    /*
     * Our virtual destructor.
     */
    file_source_complex_impl::~file_source_complex_impl()
    {
    }

    int
    file_source_complex_impl::work(int noutput_items,
        gr_vector_const_void_star &input_items,
        gr_vector_void_star &output_items)
    {
      auto out = static_cast<output_type*>(output_items[0]);

      #pragma message("Implement the signal processing in your block and remove this warning")
      // Do <+signal processing+>

      // Tell runtime system how many output items we produced.
      return noutput_items;
    }

  } /* namespace sc16io */
} /* namespace gr */
