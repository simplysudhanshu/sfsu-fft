/*=========================================================================

  Program:   Visualization Toolkit
  Module:    svtkToolkits.h.in

  Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
  All rights reserved.
  See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
#ifndef svtkToolkits_h
#define svtkToolkits_h

/* This header is configured by SVTK's build process.  */

/* The Hybrid and VolumeRendering kits are now switched with Rendering.  */
#ifdef SVTK_USE_RENDERING
# define SVTK_USE_HYBRID
# define SVTK_USE_VOLUMERENDERING
#endif

/* #undef SVTK_USE_VOLUMEPRO_1000 */

/*--------------------------------------------------------------------------*/
/* Other Configuration Options                                              */

/* Whether SVTK is using vfw32 and if it supports video capture */
/* #undef SVTK_USE_VIDEO_FOR_WINDOWS */
/* #undef SVTK_VFW_SUPPORTS_CAPTURE */

/* Whether FFMPEG is found or not  */
/* #undef SVTK_USE_FFMPEG_ENCODER */

/* Whether the user has linked in the MPEG2 library or not  */
/* #undef SVTK_USE_MPEG2_ENCODER */

/* Whether the user wants to use the Ogg/Theora encoder or not */
/* #undef SVTK_USE_OGGTHEORA_ENCODER */

#endif
