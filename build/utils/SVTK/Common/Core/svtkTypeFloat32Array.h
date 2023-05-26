/*=========================================================================

  Program:   Visualization Toolkit
  Module:    svtkTypedArray.h.in

  Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
  All rights reserved.
  See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
// .NAME svtkTypeFloat32Array - dynamic, self-adjusting array of svtkTypeFloat32
// .SECTION Description
// svtkTypeFloat32Array is an array of values of type svtkTypeFloat32.  It
// provides methods for insertion and retrieval of values and will
// automatically resize itself to hold new data.
//
// This array should be preferred for data of type Float32 as this
// array will use the correct underlying datatype based on the desired number of bits
// and the current platform.  The superclass of this type will change depending on the
// machine and compiler in use so that the data contained always uses the proper type.

#ifndef svtkTypeFloat32Array_h
#define svtkTypeFloat32Array_h

#include "svtkCommonCoreModule.h" // For export macro
#include "svtkType.h" // For native type selections.

#if SVTK_TYPE_FLOAT32 == SVTK_FLOAT
# include "svtkFloatArray.h"
# define svtkTypeArrayBase svtkFloatArray
#endif

class SVTKCOMMONCORE_EXPORT svtkTypeFloat32Array : public svtkTypeArrayBase
{
public:
  static svtkTypeFloat32Array* New();
  svtkTypeMacro(svtkTypeFloat32Array,svtkTypeArrayBase);
  void PrintSelf(ostream& os, svtkIndent indent) override;

  // Description:
  // A faster alternative to SafeDownCast for downcasting svtkAbstractArrays.
  static svtkTypeFloat32Array* FastDownCast(svtkAbstractArray *source)
  {
    return static_cast<svtkTypeFloat32Array*>(Superclass::FastDownCast(source));
  }

protected:
  svtkTypeFloat32Array();
  ~svtkTypeFloat32Array() override;

private:
  svtkTypeFloat32Array(const svtkTypeFloat32Array&) = delete;
  void operator=(const svtkTypeFloat32Array&) = delete;
};

// Define svtkArrayDownCast implementation:
svtkArrayDownCast_FastCastMacro(svtkTypeFloat32Array);

#undef svtkTypeArrayBase

#endif
// SVTK-HeaderTest-Exclude: svtkTypedArray.h.in
