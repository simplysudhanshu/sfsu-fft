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
// .NAME svtkTypeInt64Array - dynamic, self-adjusting array of svtkTypeInt64
// .SECTION Description
// svtkTypeInt64Array is an array of values of type svtkTypeInt64.  It
// provides methods for insertion and retrieval of values and will
// automatically resize itself to hold new data.
//
// This array should be preferred for data of type Int64 as this
// array will use the correct underlying datatype based on the desired number of bits
// and the current platform.  The superclass of this type will change depending on the
// machine and compiler in use so that the data contained always uses the proper type.

#ifndef svtkTypeInt64Array_h
#define svtkTypeInt64Array_h

#include "svtkCommonCoreModule.h" // For export macro
#include "svtkType.h" // For native type selections.

#if SVTK_TYPE_INT64 == SVTK_LONG
# include "svtkLongArray.h"
# define svtkTypeArrayBase svtkLongArray
#elif SVTK_TYPE_INT64 == SVTK_LONG_LONG
# include "svtkLongLongArray.h"
# define svtkTypeArrayBase svtkLongLongArray
#endif

class SVTKCOMMONCORE_EXPORT svtkTypeInt64Array : public svtkTypeArrayBase
{
public:
  static svtkTypeInt64Array* New();
  svtkTypeMacro(svtkTypeInt64Array,svtkTypeArrayBase);
  void PrintSelf(ostream& os, svtkIndent indent) override;

  // Description:
  // A faster alternative to SafeDownCast for downcasting svtkAbstractArrays.
  static svtkTypeInt64Array* FastDownCast(svtkAbstractArray *source)
  {
    return static_cast<svtkTypeInt64Array*>(Superclass::FastDownCast(source));
  }

protected:
  svtkTypeInt64Array();
  ~svtkTypeInt64Array() override;

private:
  svtkTypeInt64Array(const svtkTypeInt64Array&) = delete;
  void operator=(const svtkTypeInt64Array&) = delete;
};

// Define svtkArrayDownCast implementation:
svtkArrayDownCast_FastCastMacro(svtkTypeInt64Array);

#undef svtkTypeArrayBase

#endif
// SVTK-HeaderTest-Exclude: svtkTypedArray.h.in
