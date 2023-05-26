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
// .NAME svtkTypeUInt8Array - dynamic, self-adjusting array of svtkTypeUInt8
// .SECTION Description
// svtkTypeUInt8Array is an array of values of type svtkTypeUInt8.  It
// provides methods for insertion and retrieval of values and will
// automatically resize itself to hold new data.
//
// This array should be preferred for data of type UInt8 as this
// array will use the correct underlying datatype based on the desired number of bits
// and the current platform.  The superclass of this type will change depending on the
// machine and compiler in use so that the data contained always uses the proper type.

#ifndef svtkTypeUInt8Array_h
#define svtkTypeUInt8Array_h

#include "svtkCommonCoreModule.h" // For export macro
#include "svtkType.h" // For native type selections.

#if SVTK_TYPE_UINT8 == SVTK_UNSIGNED_CHAR
# include "svtkUnsignedCharArray.h"
# define svtkTypeArrayBase svtkUnsignedCharArray
#endif

class SVTKCOMMONCORE_EXPORT svtkTypeUInt8Array : public svtkTypeArrayBase
{
public:
  static svtkTypeUInt8Array* New();
  svtkTypeMacro(svtkTypeUInt8Array,svtkTypeArrayBase);
  void PrintSelf(ostream& os, svtkIndent indent) override;

  // Description:
  // A faster alternative to SafeDownCast for downcasting svtkAbstractArrays.
  static svtkTypeUInt8Array* FastDownCast(svtkAbstractArray *source)
  {
    return static_cast<svtkTypeUInt8Array*>(Superclass::FastDownCast(source));
  }

protected:
  svtkTypeUInt8Array();
  ~svtkTypeUInt8Array() override;

private:
  svtkTypeUInt8Array(const svtkTypeUInt8Array&) = delete;
  void operator=(const svtkTypeUInt8Array&) = delete;
};

// Define svtkArrayDownCast implementation:
svtkArrayDownCast_FastCastMacro(svtkTypeUInt8Array);

#undef svtkTypeArrayBase

#endif
// SVTK-HeaderTest-Exclude: svtkTypedArray.h.in
