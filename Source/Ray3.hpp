/******************************************************************************/
/*                                                                            */
/* Copyright 2017-2018 Steven Dolly                                           */
/*                                                                            */
/* Licensed under the Apache License, Version 2.0 (the "License");            */
/* you may not use this file except in compliance with the License.           */
/* You may obtain a copy of the License at:                                   */
/*                                                                            */
/*     http://www.apache.org/licenses/LICENSE-2.0                             */
/*                                                                            */
/* Unless required by applicable law or agreed to in writing, software        */
/* distributed under the License is distributed on an "AS IS" BASIS,          */
/* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.   */
/* See the License for the specific language governing permissions and        */
/* limitations under the License.                                             */
/*                                                                            */
/******************************************************************************/

////////////////////////////////////////////////////////////////////////////////
//                                                                            //
// Ray3.hpp                                                                   //
// 3D Ray Class Header File                                                   //
// Created June 1, 2017 (Steven Dolly)                                        //
//                                                                            //
// This header file contains a template class for a generalized three-        //
// dimensional ray, with simple math operation functions.                     //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////

// Header guard
#ifndef RAY3_HPP
#define RAY3_HPP

// Standard C header files
#include <cmath>

// Custom headers
#include "Vec3.hpp"

namespace rayphys
{
  template <class T>
  class Ray3
  {
    public:
      // Default constructor (set to all zeros)
      Ray3();
      // Constructor with origin and direction setter
      Ray3(Vec3<T> o, Vec3<T> d);
      // Ray origin & direction
      Vec3<T> origin, direction;
      // Set functions
      void SetRay(Vec3<T> o, Vec3<T> d);
      // Get functions
      Vec3<T> GetPoint(T t);
      T GetLength();
  };
  
  //////////////////////////
  // Ray member functions //
  //////////////////////////
  
  // Default constructor (set to all zeros)
  template <class T>
  Ray3<T>::Ray3()
  {
    Vec3<T> o, d;
    SetRay(o, d);
  }
  // Constructor with origin and direction setter
  template <class T>
  Ray3<T>::Ray3(Vec3<T> o, Vec3<T> d)
  {
    SetRay(o, d);
  }
  // Set ray origin and direction
  template <class T>
  void Ray3<T>::SetRay(Vec3<T> o, Vec3<T> d)
  {
    origin = o;
    direction = d;
  }
  // Get point based on ray parameter
  template <class T>
  Vec3<T> Ray3<T>::GetPoint(T t)
  {
    Vec3<T> point;
    point.x = origin.x + t*direction.x;
    point.y = origin.y + t*direction.y;
    point.z = origin.z + t*direction.z;
    return point;
  }
  // Get length of ray based on direction vector
  template <class T>
  T Ray3<T>::GetLength()
  {
    return direction.Magnitude();
  }
}

#endif
