find_package(PkgConfig)

PKG_CHECK_MODULES(PC_GR_SC16IO gnuradio-sc16io)

FIND_PATH(
    GR_SC16IO_INCLUDE_DIRS
    NAMES gnuradio/sc16io/api.h
    HINTS $ENV{SC16IO_DIR}/include
        ${PC_SC16IO_INCLUDEDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/include
          /usr/local/include
          /usr/include
)

FIND_LIBRARY(
    GR_SC16IO_LIBRARIES
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

include("${CMAKE_CURRENT_LIST_DIR}/gnuradio-sc16ioTarget.cmake")

INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(GR_SC16IO DEFAULT_MSG GR_SC16IO_LIBRARIES GR_SC16IO_INCLUDE_DIRS)
MARK_AS_ADVANCED(GR_SC16IO_LIBRARIES GR_SC16IO_INCLUDE_DIRS)
