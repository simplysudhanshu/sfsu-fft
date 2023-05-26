// -*- c++ -*-
/*=========================================================================

  Program:   Visualization Toolkit
  Module:    svtkFloatingPointExceptionsConfigure.h.in

  Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
  All rights reserved.
  See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/

#ifndef svtkFloatingPointExceptionsConfigure_h
#define svtkFloatingPointExceptionsConfigure_h

#define SVTK_HAS_FEENABLEEXCEPT

// SVTK_HAS_FEENABLEEXCEPT is only defined if the function exists.
#if defined(SVTK_HAS_FEENABLEEXCEPT) && defined(_GNU_SOURCE)
# define SVTK_USE_FENV 1
#endif

#endif //svtkFloatingPointExceptionsConfigure_h
