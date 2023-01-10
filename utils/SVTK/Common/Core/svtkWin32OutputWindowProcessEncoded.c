/*=========================================================================

  Program:   Visualization Toolkit
  Module:    svtkWin32OutputWindowProcessEncoded.c

  Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
  All rights reserved.
  See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
/*

DO NOT EDIT

This file is generated by running CMake on
SVTK/Utilities/OutputWindowProcess as a separate project using a Visual
Studio generator.  The program built in that project works only when
compiled by the Visual Studio compiler because it depends on being
able to manipulate the stack frame of another process.  See
SVTK/Utilities/OutputWindowProcess/README.txt for more information.

This file contains an encoded executable that can be written to disk using

  int svtkEncodedArrayWin32OutputWindowProcessWrite(const char* fname);

It returns 1 for success and 0 for failure.  The executable is
self-deleting and therefore can be run only once.  It is used by
svtkWin32ProcessOutputWindow.

*/

#include <stdio.h>

#include "svtkWin32OutputWindowProcessEncodedData.c"

extern int svtkEncodedArrayWin32OutputWindowProcessWrite(const char* fname)
{
  FILE* ofp = fopen(fname, "wb");
  if (!ofp)
  {
    return 0;
  }
  if (fwrite(svtkEncodedArrayWin32OutputWindowProcess_0, 1,
        sizeof(svtkEncodedArrayWin32OutputWindowProcess_0),
        ofp) != sizeof(svtkEncodedArrayWin32OutputWindowProcess_0))
  {
    fclose(ofp);
    _unlink(fname);
    return 0;
  }
  if (fwrite(svtkEncodedArrayWin32OutputWindowProcess_1, 1,
        sizeof(svtkEncodedArrayWin32OutputWindowProcess_1),
        ofp) != sizeof(svtkEncodedArrayWin32OutputWindowProcess_1))
  {
    fclose(ofp);
    _unlink(fname);
    return 0;
  }
  if (fwrite(svtkEncodedArrayWin32OutputWindowProcess_2, 1,
        sizeof(svtkEncodedArrayWin32OutputWindowProcess_2),
        ofp) != sizeof(svtkEncodedArrayWin32OutputWindowProcess_2))
  {
    fclose(ofp);
    _unlink(fname);
    return 0;
  }
  if (fwrite(svtkEncodedArrayWin32OutputWindowProcess_3, 1,
        sizeof(svtkEncodedArrayWin32OutputWindowProcess_3),
        ofp) != sizeof(svtkEncodedArrayWin32OutputWindowProcess_3))
  {
    fclose(ofp);
    _unlink(fname);
    return 0;
  }
  if (fwrite(svtkEncodedArrayWin32OutputWindowProcess_4, 1,
        sizeof(svtkEncodedArrayWin32OutputWindowProcess_4),
        ofp) != sizeof(svtkEncodedArrayWin32OutputWindowProcess_4))
  {
    fclose(ofp);
    _unlink(fname);
    return 0;
  }
  if (fwrite(svtkEncodedArrayWin32OutputWindowProcess_5, 1,
        sizeof(svtkEncodedArrayWin32OutputWindowProcess_5),
        ofp) != sizeof(svtkEncodedArrayWin32OutputWindowProcess_5))
  {
    fclose(ofp);
    _unlink(fname);
    return 0;
  }
  if (fwrite(svtkEncodedArrayWin32OutputWindowProcess_6, 1,
        sizeof(svtkEncodedArrayWin32OutputWindowProcess_6),
        ofp) != sizeof(svtkEncodedArrayWin32OutputWindowProcess_6))
  {
    fclose(ofp);
    _unlink(fname);
    return 0;
  }
  if (fwrite(svtkEncodedArrayWin32OutputWindowProcess_7, 1,
        sizeof(svtkEncodedArrayWin32OutputWindowProcess_7),
        ofp) != sizeof(svtkEncodedArrayWin32OutputWindowProcess_7))
  {
    fclose(ofp);
    _unlink(fname);
    return 0;
  }
  if (fwrite(svtkEncodedArrayWin32OutputWindowProcess_8, 1,
        sizeof(svtkEncodedArrayWin32OutputWindowProcess_8),
        ofp) != sizeof(svtkEncodedArrayWin32OutputWindowProcess_8))
  {
    fclose(ofp);
    _unlink(fname);
    return 0;
  }
  if (fwrite(svtkEncodedArrayWin32OutputWindowProcess_9, 1,
        sizeof(svtkEncodedArrayWin32OutputWindowProcess_9),
        ofp) != sizeof(svtkEncodedArrayWin32OutputWindowProcess_9))
  {
    fclose(ofp);
    _unlink(fname);
    return 0;
  }
  if (fwrite(svtkEncodedArrayWin32OutputWindowProcess_10, 1,
        sizeof(svtkEncodedArrayWin32OutputWindowProcess_10),
        ofp) != sizeof(svtkEncodedArrayWin32OutputWindowProcess_10))
  {
    fclose(ofp);
    _unlink(fname);
    return 0;
  }
  if (fwrite(svtkEncodedArrayWin32OutputWindowProcess_11, 1,
        sizeof(svtkEncodedArrayWin32OutputWindowProcess_11),
        ofp) != sizeof(svtkEncodedArrayWin32OutputWindowProcess_11))
  {
    fclose(ofp);
    _unlink(fname);
    return 0;
  }
  if (fwrite(svtkEncodedArrayWin32OutputWindowProcess_12, 1,
        sizeof(svtkEncodedArrayWin32OutputWindowProcess_12),
        ofp) != sizeof(svtkEncodedArrayWin32OutputWindowProcess_12))
  {
    fclose(ofp);
    _unlink(fname);
    return 0;
  }
  if (fwrite(svtkEncodedArrayWin32OutputWindowProcess_13, 1,
        sizeof(svtkEncodedArrayWin32OutputWindowProcess_13),
        ofp) != sizeof(svtkEncodedArrayWin32OutputWindowProcess_13))
  {
    fclose(ofp);
    _unlink(fname);
    return 0;
  }
  if (fwrite(svtkEncodedArrayWin32OutputWindowProcess_14, 1,
        sizeof(svtkEncodedArrayWin32OutputWindowProcess_14),
        ofp) != sizeof(svtkEncodedArrayWin32OutputWindowProcess_14))
  {
    fclose(ofp);
    _unlink(fname);
    return 0;
  }
  if (fwrite(svtkEncodedArrayWin32OutputWindowProcess_15, 1,
        sizeof(svtkEncodedArrayWin32OutputWindowProcess_15),
        ofp) != sizeof(svtkEncodedArrayWin32OutputWindowProcess_15))
  {
    fclose(ofp);
    _unlink(fname);
    return 0;
  }
  if (fwrite(svtkEncodedArrayWin32OutputWindowProcess_16, 1,
        sizeof(svtkEncodedArrayWin32OutputWindowProcess_16),
        ofp) != sizeof(svtkEncodedArrayWin32OutputWindowProcess_16))
  {
    fclose(ofp);
    _unlink(fname);
    return 0;
  }
  if (fwrite(svtkEncodedArrayWin32OutputWindowProcess_17, 1,
        sizeof(svtkEncodedArrayWin32OutputWindowProcess_17),
        ofp) != sizeof(svtkEncodedArrayWin32OutputWindowProcess_17))
  {
    fclose(ofp);
    _unlink(fname);
    return 0;
  }
  if (fwrite(svtkEncodedArrayWin32OutputWindowProcess_18, 1,
        sizeof(svtkEncodedArrayWin32OutputWindowProcess_18),
        ofp) != sizeof(svtkEncodedArrayWin32OutputWindowProcess_18))
  {
    fclose(ofp);
    _unlink(fname);
    return 0;
  }
  if (fwrite(svtkEncodedArrayWin32OutputWindowProcess_19, 1,
        sizeof(svtkEncodedArrayWin32OutputWindowProcess_19),
        ofp) != sizeof(svtkEncodedArrayWin32OutputWindowProcess_19))
  {
    fclose(ofp);
    _unlink(fname);
    return 0;
  }
  if (fwrite(svtkEncodedArrayWin32OutputWindowProcess_20, 1,
        sizeof(svtkEncodedArrayWin32OutputWindowProcess_20),
        ofp) != sizeof(svtkEncodedArrayWin32OutputWindowProcess_20))
  {
    fclose(ofp);
    _unlink(fname);
    return 0;
  }
  if (fwrite(svtkEncodedArrayWin32OutputWindowProcess_21, 1,
        sizeof(svtkEncodedArrayWin32OutputWindowProcess_21),
        ofp) != sizeof(svtkEncodedArrayWin32OutputWindowProcess_21))
  {
    fclose(ofp);
    _unlink(fname);
    return 0;
  }
  if (fwrite(svtkEncodedArrayWin32OutputWindowProcess_22, 1,
        sizeof(svtkEncodedArrayWin32OutputWindowProcess_22),
        ofp) != sizeof(svtkEncodedArrayWin32OutputWindowProcess_22))
  {
    fclose(ofp);
    _unlink(fname);
    return 0;
  }
  if (fwrite(svtkEncodedArrayWin32OutputWindowProcess_23, 1,
        sizeof(svtkEncodedArrayWin32OutputWindowProcess_23),
        ofp) != sizeof(svtkEncodedArrayWin32OutputWindowProcess_23))
  {
    fclose(ofp);
    _unlink(fname);
    return 0;
  }
  if (fwrite(svtkEncodedArrayWin32OutputWindowProcess_24, 1,
        sizeof(svtkEncodedArrayWin32OutputWindowProcess_24),
        ofp) != sizeof(svtkEncodedArrayWin32OutputWindowProcess_24))
  {
    fclose(ofp);
    _unlink(fname);
    return 0;
  }
  if (fwrite(svtkEncodedArrayWin32OutputWindowProcess_25, 1,
        sizeof(svtkEncodedArrayWin32OutputWindowProcess_25),
        ofp) != sizeof(svtkEncodedArrayWin32OutputWindowProcess_25))
  {
    fclose(ofp);
    _unlink(fname);
    return 0;
  }
  if (fwrite(svtkEncodedArrayWin32OutputWindowProcess_26, 1,
        sizeof(svtkEncodedArrayWin32OutputWindowProcess_26),
        ofp) != sizeof(svtkEncodedArrayWin32OutputWindowProcess_26))
  {
    fclose(ofp);
    _unlink(fname);
    return 0;
  }
  if (fwrite(svtkEncodedArrayWin32OutputWindowProcess_27, 1,
        sizeof(svtkEncodedArrayWin32OutputWindowProcess_27),
        ofp) != sizeof(svtkEncodedArrayWin32OutputWindowProcess_27))
  {
    fclose(ofp);
    _unlink(fname);
    return 0;
  }
  fclose(ofp);
  return 1;
}