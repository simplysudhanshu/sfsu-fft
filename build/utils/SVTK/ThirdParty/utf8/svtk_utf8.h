/*=========================================================================

  Program:   Visualization Toolkit
  Module:    svtk_utf8.h

  Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
  All rights reserved.
  See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
#ifndef svtk_utf8_h
#define svtk_utf8_h

/* Use the utf8cpp library configured for SVTK.  */
#define SVTK_MODULE_USE_EXTERNAL_svtkutf8 0

#if SVTK_MODULE_USE_EXTERNAL_svtkutf8
# include <utf8.h>
#else
# include <svtkutf8/utf8.h>
namespace utf8 = svtk_utf8;
#endif

#endif
