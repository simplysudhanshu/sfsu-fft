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
// .NAME svtkTypeUInt16Array - dynamic, self-adjusting array of svtkTypeUInt16
// .SECTION Description
// svtkTypeUInt16Array is an array of values of type svtkTypeUInt16.  It
// provides methods for insertion and retrieval of values and will
// automatically resize itself to hold new data.
//
// This array should be preferred for data of type UInt16 as this
// array will use the correct underlying datatype based on the desired number of bits
// and the current platform.  The superclass of this type will change depending on the
// machine and compiler in use so that the data contained always uses the proper type.

#ifndef svtkTypeUInt16Array_h
#define svtkTypeUInt16Array_h

#include "svtkCommonCoreModule.h" // For export macro
#include "svtkType.h" // For native type selections.

#if SVTK_TYPE_UINT16 == SVTK_UNSIGNED_SHORT
# include "svtkUnsignedShortArray.h"
# define svtkTypeArrayBase svtkUnsignedShortArray
#endif

class SVTKCOMMONCORE_EXPORT svtkTypeUInt16Array : public svtkTypeArrayBase
{
public:
  static svtkTypeUInt16Array* New();
  svtkTypeMacro(svtkTypeUInt16Array,svtkTypeArrayBase);
  void PrintSelf(ostream& os, svtkIndent indent) override;

  // Description:
  // A faster alternative to SafeDownCast for downcasting svtkAbstractArrays.
  static svtkTypeUInt16Array* FastDownCast(svtkAbstractArray *source)
  {
    return static_cast<svtkTypeUInt16Array*>(Superclass::FastDownCast(source));
  }

protected:
  svtkTypeUInt16Array();
  ~svtkTypeUInt16Array() override;

private:
  svtkTypeUInt16Array(const svtkTypeUInt16Array&) = delete;
  void operator=(const svtkTypeUInt16Array&) = delete;
};

// Define svtkArrayDownCast implementation:
svtkArrayDownCast_FastCastMacro(svtkTypeUInt16Array);

#undef svtkTypeArrayBase

#endif
// SVTK-HeaderTest-Exclude: svtkTypedArray.h.in
