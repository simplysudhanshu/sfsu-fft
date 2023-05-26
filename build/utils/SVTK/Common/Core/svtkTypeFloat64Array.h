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
// .NAME svtkTypeFloat64Array - dynamic, self-adjusting array of svtkTypeFloat64
// .SECTION Description
// svtkTypeFloat64Array is an array of values of type svtkTypeFloat64.  It
// provides methods for insertion and retrieval of values and will
// automatically resize itself to hold new data.
//
// This array should be preferred for data of type Float64 as this
// array will use the correct underlying datatype based on the desired number of bits
// and the current platform.  The superclass of this type will change depending on the
// machine and compiler in use so that the data contained always uses the proper type.

#ifndef svtkTypeFloat64Array_h
#define svtkTypeFloat64Array_h

#include "svtkCommonCoreModule.h" // For export macro
#include "svtkType.h" // For native type selections.

#if SVTK_TYPE_FLOAT64 == SVTK_DOUBLE
# include "svtkDoubleArray.h"
# define svtkTypeArrayBase svtkDoubleArray
#endif

class SVTKCOMMONCORE_EXPORT svtkTypeFloat64Array : public svtkTypeArrayBase
{
public:
  static svtkTypeFloat64Array* New();
  svtkTypeMacro(svtkTypeFloat64Array,svtkTypeArrayBase);
  void PrintSelf(ostream& os, svtkIndent indent) override;

  // Description:
  // A faster alternative to SafeDownCast for downcasting svtkAbstractArrays.
  static svtkTypeFloat64Array* FastDownCast(svtkAbstractArray *source)
  {
    return static_cast<svtkTypeFloat64Array*>(Superclass::FastDownCast(source));
  }

protected:
  svtkTypeFloat64Array();
  ~svtkTypeFloat64Array() override;

private:
  svtkTypeFloat64Array(const svtkTypeFloat64Array&) = delete;
  void operator=(const svtkTypeFloat64Array&) = delete;
};

// Define svtkArrayDownCast implementation:
svtkArrayDownCast_FastCastMacro(svtkTypeFloat64Array);

#undef svtkTypeArrayBase

#endif
// SVTK-HeaderTest-Exclude: svtkTypedArray.h.in
