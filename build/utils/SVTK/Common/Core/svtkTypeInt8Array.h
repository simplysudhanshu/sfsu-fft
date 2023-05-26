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
// .NAME svtkTypeInt8Array - dynamic, self-adjusting array of svtkTypeInt8
// .SECTION Description
// svtkTypeInt8Array is an array of values of type svtkTypeInt8.  It
// provides methods for insertion and retrieval of values and will
// automatically resize itself to hold new data.
//
// This array should be preferred for data of type Int8 as this
// array will use the correct underlying datatype based on the desired number of bits
// and the current platform.  The superclass of this type will change depending on the
// machine and compiler in use so that the data contained always uses the proper type.

#ifndef svtkTypeInt8Array_h
#define svtkTypeInt8Array_h

#include "svtkCommonCoreModule.h" // For export macro
#include "svtkType.h" // For native type selections.

#if SVTK_TYPE_INT8 == SVTK_CHAR
# include "svtkCharArray.h"
# define svtkTypeArrayBase svtkCharArray
#else
# include "svtkSignedCharArray.h"
# define svtkTypeArrayBase svtkSignedCharArray
#endif

class SVTKCOMMONCORE_EXPORT svtkTypeInt8Array : public svtkTypeArrayBase
{
public:
  static svtkTypeInt8Array* New();
  svtkTypeMacro(svtkTypeInt8Array,svtkTypeArrayBase);
  void PrintSelf(ostream& os, svtkIndent indent) override;

  // Description:
  // A faster alternative to SafeDownCast for downcasting svtkAbstractArrays.
  static svtkTypeInt8Array* FastDownCast(svtkAbstractArray *source)
  {
    return static_cast<svtkTypeInt8Array*>(Superclass::FastDownCast(source));
  }

protected:
  svtkTypeInt8Array();
  ~svtkTypeInt8Array() override;

private:
  svtkTypeInt8Array(const svtkTypeInt8Array&) = delete;
  void operator=(const svtkTypeInt8Array&) = delete;
};

// Define svtkArrayDownCast implementation:
svtkArrayDownCast_FastCastMacro(svtkTypeInt8Array);

#undef svtkTypeArrayBase

#endif
// SVTK-HeaderTest-Exclude: svtkTypedArray.h.in
