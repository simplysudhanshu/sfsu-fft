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
// .NAME svtkTypeUInt32Array - dynamic, self-adjusting array of svtkTypeUInt32
// .SECTION Description
// svtkTypeUInt32Array is an array of values of type svtkTypeUInt32.  It
// provides methods for insertion and retrieval of values and will
// automatically resize itself to hold new data.
//
// This array should be preferred for data of type UInt32 as this
// array will use the correct underlying datatype based on the desired number of bits
// and the current platform.  The superclass of this type will change depending on the
// machine and compiler in use so that the data contained always uses the proper type.

#ifndef svtkTypeUInt32Array_h
#define svtkTypeUInt32Array_h

#include "svtkCommonCoreModule.h" // For export macro
#include "svtkType.h" // For native type selections.

#if SVTK_TYPE_UINT32 == SVTK_UNSIGNED_INT
# include "svtkUnsignedIntArray.h"
# define svtkTypeArrayBase svtkUnsignedIntArray
#endif

class SVTKCOMMONCORE_EXPORT svtkTypeUInt32Array : public svtkTypeArrayBase
{
public:
  static svtkTypeUInt32Array* New();
  svtkTypeMacro(svtkTypeUInt32Array,svtkTypeArrayBase);
  void PrintSelf(ostream& os, svtkIndent indent) override;

  // Description:
  // A faster alternative to SafeDownCast for downcasting svtkAbstractArrays.
  static svtkTypeUInt32Array* FastDownCast(svtkAbstractArray *source)
  {
    return static_cast<svtkTypeUInt32Array*>(Superclass::FastDownCast(source));
  }

protected:
  svtkTypeUInt32Array();
  ~svtkTypeUInt32Array() override;

private:
  svtkTypeUInt32Array(const svtkTypeUInt32Array&) = delete;
  void operator=(const svtkTypeUInt32Array&) = delete;
};

// Define svtkArrayDownCast implementation:
svtkArrayDownCast_FastCastMacro(svtkTypeUInt32Array);

#undef svtkTypeArrayBase

#endif
// SVTK-HeaderTest-Exclude: svtkTypedArray.h.in
