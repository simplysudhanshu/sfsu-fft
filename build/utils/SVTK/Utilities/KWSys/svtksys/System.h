/* Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
   file Copyright.txt or https://cmake.org/licensing#kwsys for details.  */
#ifndef svtksys_System_h
#define svtksys_System_h

#include <svtksys/Configure.h>

/* Redefine all public interface symbol names to be in the proper
   namespace.  These macros are used internally to kwsys only, and are
   not visible to user code.  Use kwsysHeaderDump.pl to reproduce
   these macros after making changes to the interface.  */
#if !defined(KWSYS_NAMESPACE)
#  define kwsys_ns(x) svtksys##x
#  define kwsysEXPORT svtksys_EXPORT
#endif
#if !svtksys_NAME_IS_KWSYS
#  define kwsysSystem_Parse_CommandForUnix                                    \
    kwsys_ns(System_Parse_CommandForUnix)
#endif

#if defined(__cplusplus)
extern "C" {
#endif

/**
 * Parse a unix-style command line string into separate arguments.
 *
 * On success, returns a pointer to an array of pointers to individual
 * argument strings.  Each string is null-terminated and the last
 * entry in the array is a NULL pointer (just like argv).  It is the
 * caller's responsibility to free() the strings and the array of
 * pointers to them.
 *
 * On failure, returns NULL.  Failure occurs only on invalid flags or
 * when memory cannot be allocated; never due to content of the input
 * string.  Missing close-quotes are treated as if the necessary
 * closing quote appears.
 *
 * By default single- and double-quoted arguments are supported, and
 * any character may be escaped by a backslash.  The flags argument is
 * reserved for future use, and must be zero (or the call will fail).
 */
kwsysEXPORT char** kwsysSystem_Parse_CommandForUnix(const char* command,
                                                    int flags);

#if defined(__cplusplus)
} /* extern "C" */
#endif

/* If we are building a kwsys .c or .cxx file, let it use these macros.
   Otherwise, undefine them to keep the namespace clean.  */
#if !defined(KWSYS_NAMESPACE)
#  undef kwsys_ns
#  undef kwsysEXPORT
#  if !defined(KWSYS_NAMESPACE) && !svtksys_NAME_IS_KWSYS
#    undef kwsysSystem_Parse_CommandForUnix
#  endif
#endif

#endif
