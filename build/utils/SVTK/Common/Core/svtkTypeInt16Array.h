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
// .NAME svtkTypeInt16Array - dynamic, self-adjusting array of svtkTypeInt16
// .SECTION Description
// svtkTypeInt16Array is an array of values of type svtkTypeInt16.  It
// provides methods for insertion and retrieval of values and will
// automatically resize itself to hold new data.
//
// This array should be preferred for data of type Int16 as this
// array will use the correct underlying datatype based on the desired number of bits
// and the current platform.  The superclass of this type will change depending on the
// machine and compiler in use so that the data contained always uses the proper type.

#ifndef svtkTypeInt16Array_h
#define svtkTypeInt16Array_h

#include "svtkCommonCoreModule.h" // For export macro
#include "svtkType.h" // For native type selections.

#if SVTK_TYPE_INT16 == SVTK_SHORT
# include "svtkShortArray.h"
# define svtkTypeArrayBase svtkShortArray
#endif

class SVTKCOMMONCORE_EXPORT svtkTypeInt16Array : public svtkTypeArrayBase
{
public:
  static svtkTypeInt16Array* New();
  svtkTypeMacro(svtkTypeInt16Array,svtkTypeArrayBase);
  void PrintSelf(ostream& os, svtkIndent indent) override;

  // Description:
  // A faster alternative to SafeDownCast for downcasting svtkAbstractArrays.
  static svtkTypeInt16Array* FastDownCast(svtkAbstractArray *source)
  {
    return static_cast<svtkTypeInt16Array*>(Superclass::FastDownCast(source));
  }

protected:
  svtkTypeInt16Array();
  ~svtkTypeInt16Array() override;

private:
  svtkTypeInt16Array(const svtkTypeInt16Array&) = delete;
  void operator=(const svtkTypeInt16Array&) = delete;
};

// Define svtkArrayDownCast implementation:
svtkArrayDownCast_FastCastMacro(svtkTypeInt16Array);

#undef svtkTypeArrayBase

#endif
// SVTK-HeaderTest-Exclude: svtkTypedArray.h.in
