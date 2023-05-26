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
// .NAME svtkTypeInt32Array - dynamic, self-adjusting array of svtkTypeInt32
// .SECTION Description
// svtkTypeInt32Array is an array of values of type svtkTypeInt32.  It
// provides methods for insertion and retrieval of values and will
// automatically resize itself to hold new data.
//
// This array should be preferred for data of type Int32 as this
// array will use the correct underlying datatype based on the desired number of bits
// and the current platform.  The superclass of this type will change depending on the
// machine and compiler in use so that the data contained always uses the proper type.

#ifndef svtkTypeInt32Array_h
#define svtkTypeInt32Array_h

#include "svtkCommonCoreModule.h" // For export macro
#include "svtkType.h" // For native type selections.

#if SVTK_TYPE_INT32 == SVTK_INT
# include "svtkIntArray.h"
# define svtkTypeArrayBase svtkIntArray
#endif

class SVTKCOMMONCORE_EXPORT svtkTypeInt32Array : public svtkTypeArrayBase
{
public:
  static svtkTypeInt32Array* New();
  svtkTypeMacro(svtkTypeInt32Array,svtkTypeArrayBase);
  void PrintSelf(ostream& os, svtkIndent indent) override;

  // Description:
  // A faster alternative to SafeDownCast for downcasting svtkAbstractArrays.
  static svtkTypeInt32Array* FastDownCast(svtkAbstractArray *source)
  {
    return static_cast<svtkTypeInt32Array*>(Superclass::FastDownCast(source));
  }

protected:
  svtkTypeInt32Array();
  ~svtkTypeInt32Array() override;

private:
  svtkTypeInt32Array(const svtkTypeInt32Array&) = delete;
  void operator=(const svtkTypeInt32Array&) = delete;
};

// Define svtkArrayDownCast implementation:
svtkArrayDownCast_FastCastMacro(svtkTypeInt32Array);

#undef svtkTypeArrayBase

#endif
// SVTK-HeaderTest-Exclude: svtkTypedArray.h.in
