/* -*- c++ -*- */
/*
 * Copyright 2026 Hannan.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef INCLUDED_SC16IO_FILE_SOURCE_COMPLEX_H
#define INCLUDED_SC16IO_FILE_SOURCE_COMPLEX_H

#include <gnuradio/sc16io/api.h>
#include <gnuradio/sync_block.h>

namespace gr {
  namespace sc16io {

    /*!
     * \brief <+description of block+>
     * \ingroup sc16io
     *
     */
    class SC16IO_API file_source_complex : virtual public gr::sync_block
    {
     public:
      typedef std::shared_ptr<file_source_complex> sptr;

      /*!
       * \brief Return a shared_ptr to a new instance of sc16io::file_source_complex.
       *
       * To avoid accidental use of raw pointers, sc16io::file_source_complex's
       * constructor is in a private implementation
       * class. sc16io::file_source_complex::make is the public interface for
       * creating new instances.
       */
      static sptr make(std::string filename, std::string source_type="complex16", bool repeat=false);
    };

  } // namespace sc16io
} // namespace gr

#endif /* INCLUDED_SC16IO_FILE_SOURCE_COMPLEX_H */
