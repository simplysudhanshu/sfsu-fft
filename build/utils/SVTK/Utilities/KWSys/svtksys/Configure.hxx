/* Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
   file Copyright.txt or https://cmake.org/licensing#kwsys for details.  */
#ifndef svtksys_Configure_hxx
#define svtksys_Configure_hxx

/* Include C configuration.  */
#include <svtksys/Configure.h>

/* Whether wstring is available.  */
#define svtksys_STL_HAS_WSTRING 1
/* Whether <ext/stdio_filebuf.h> is available. */
#define svtksys_CXX_HAS_EXT_STDIO_FILEBUF_H                         \
  1
/* Whether the translation map is available or not. */
#define svtksys_SYSTEMTOOLS_USE_TRANSLATION_MAP                     \
  1

#if defined(__SUNPRO_CC) && __SUNPRO_CC > 0x5130 && defined(__has_attribute)
#  define svtksys__has_cpp_attribute(x) __has_attribute(x)
#elif defined(__has_cpp_attribute)
#  define svtksys__has_cpp_attribute(x) __has_cpp_attribute(x)
#else
#  define svtksys__has_cpp_attribute(x) 0
#endif

#if __cplusplus >= 201103L
#  define svtksys_NULLPTR nullptr
#else
#  define svtksys_NULLPTR 0
#endif

#ifndef svtksys_FALLTHROUGH
#  if __cplusplus >= 201703L &&                                               \
    svtksys__has_cpp_attribute(fallthrough)
#    define svtksys_FALLTHROUGH [[fallthrough]]
#  elif __cplusplus >= 201103L &&                                             \
    svtksys__has_cpp_attribute(gnu::fallthrough)
#    define svtksys_FALLTHROUGH [[gnu::fallthrough]]
#  elif __cplusplus >= 201103L &&                                             \
    svtksys__has_cpp_attribute(clang::fallthrough)
#    define svtksys_FALLTHROUGH [[clang::fallthrough]]
#  endif
#endif
#ifndef svtksys_FALLTHROUGH
#  define svtksys_FALLTHROUGH static_cast<void>(0)
#endif

#undef svtksys__has_cpp_attribute

/* If building a C++ file in kwsys itself, give the source file
   access to the macros without a configured namespace.  */
#if defined(KWSYS_NAMESPACE)
#  if !svtksys_NAME_IS_KWSYS
#    define kwsys svtksys
#  endif
#  define KWSYS_NAME_IS_KWSYS svtksys_NAME_IS_KWSYS
#  define KWSYS_STL_HAS_WSTRING svtksys_STL_HAS_WSTRING
#  define KWSYS_CXX_HAS_EXT_STDIO_FILEBUF_H                                   \
    svtksys_CXX_HAS_EXT_STDIO_FILEBUF_H
#  define KWSYS_FALLTHROUGH svtksys_FALLTHROUGH
#  define KWSYS_SYSTEMTOOLS_USE_TRANSLATION_MAP                               \
    svtksys_SYSTEMTOOLS_USE_TRANSLATION_MAP
#endif

#endif
