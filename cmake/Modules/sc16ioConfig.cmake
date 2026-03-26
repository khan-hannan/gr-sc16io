INCLUDE(FindPkgConfig)
PKG_CHECK_MODULES(PC_SC16IO sc16io)

FIND_PATH(
    SC16IO_INCLUDE_DIRS
    NAMES sc16io/api.h
    HINTS $ENV{SC16IO_DIR}/include
        ${PC_SC16IO_INCLUDEDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/include
          /usr/local/include
          /usr/include
)

FIND_LIBRARY(
    SC16IO_LIBRARIES
    NAMES gnuradio-sc16io
    HINTS $ENV{SC16IO_DIR}/lib
        ${PC_SC16IO_LIBDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/lib
          ${CMAKE_INSTALL_PREFIX}/lib64
          /usr/local/lib
          /usr/local/lib64
          /usr/lib
          /usr/lib64
          )

include("${CMAKE_CURRENT_LIST_DIR}/sc16ioTarget.cmake")

INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(SC16IO DEFAULT_MSG SC16IO_LIBRARIES SC16IO_INCLUDE_DIRS)
MARK_AS_ADVANCED(SC16IO_LIBRARIES SC16IO_INCLUDE_DIRS)
