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
// .NAME svtkTypeUInt64Array - dynamic, self-adjusting array of svtkTypeUInt64
// .SECTION Description
// svtkTypeUInt64Array is an array of values of type svtkTypeUInt64.  It
// provides methods for insertion and retrieval of values and will
// automatically resize itself to hold new data.
//
// This array should be preferred for data of type UInt64 as this
// array will use the correct underlying datatype based on the desired number of bits
// and the current platform.  The superclass of this type will change depending on the
// machine and compiler in use so that the data contained always uses the proper type.

#ifndef svtkTypeUInt64Array_h
#define svtkTypeUInt64Array_h

#include "svtkCommonCoreModule.h" // For export macro
#include "svtkType.h" // For native type selections.

#if SVTK_TYPE_UINT64 == SVTK_UNSIGNED_LONG
# include "svtkUnsignedLongArray.h"
# define svtkTypeArrayBase svtkUnsignedLongArray
#elif SVTK_TYPE_UINT64 == SVTK_UNSIGNED_LONG_LONG
# include "svtkUnsignedLongLongArray.h"
# define svtkTypeArrayBase svtkUnsignedLongLongArray
#endif

class SVTKCOMMONCORE_EXPORT svtkTypeUInt64Array : public svtkTypeArrayBase
{
public:
  static svtkTypeUInt64Array* New();
  svtkTypeMacro(svtkTypeUInt64Array,svtkTypeArrayBase);
  void PrintSelf(ostream& os, svtkIndent indent) override;

  // Description:
  // A faster alternative to SafeDownCast for downcasting svtkAbstractArrays.
  static svtkTypeUInt64Array* FastDownCast(svtkAbstractArray *source)
  {
    return static_cast<svtkTypeUInt64Array*>(Superclass::FastDownCast(source));
  }

protected:
  svtkTypeUInt64Array();
  ~svtkTypeUInt64Array() override;

private:
  svtkTypeUInt64Array(const svtkTypeUInt64Array&) = delete;
  void operator=(const svtkTypeUInt64Array&) = delete;
};

// Define svtkArrayDownCast implementation:
svtkArrayDownCast_FastCastMacro(svtkTypeUInt64Array);

#undef svtkTypeArrayBase

#endif
// SVTK-HeaderTest-Exclude: svtkTypedArray.h.in
