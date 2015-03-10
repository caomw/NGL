/*
  Copyright (C) 2009 Jon Macey

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#ifndef UTIL_H__
#define UTIL_H__
// must include types.h first for Real and GLEW if required
#include "Types.h"
#include <glm/vec4.hpp>
#include <glm/vec3.hpp>
#include <glm/mat4x4.hpp>

#include <cmath>
#include <string>
//----------------------------------------------------------------------------------------------------------------------
/// @file Util.h
/// @brief some useful definitions and functions
//----------------------------------------------------------------------------------------------------------------------

namespace ngl
{
//----------------------------------------------------------------------------------------------------------------------
/// @file Util.h
/// @author Jonathan Macey
/// @version 1.2
/// @date 24/11/04
/// @brief lots of usful functions for ngl
//----------------------------------------------------------------------------------------------------------------------
/// @brief  pre-compute the value for value for 2*PI convert to float to suppress windows warning as well
//----------------------------------------------------------------------------------------------------------------------
const static Real TWO_PI= Real(2*M_PI); //6.28318530717958647692   //360
//----------------------------------------------------------------------------------------------------------------------
/// @brief  pre-compute the value for value for PI based on system M_PI
//----------------------------------------------------------------------------------------------------------------------
const static Real PI=Real(M_PI); //3.14159265358979323846       //180
//----------------------------------------------------------------------------------------------------------------------
/// @brief  pre-compute the value for value for PI/2.0
//----------------------------------------------------------------------------------------------------------------------
const static Real PI2=Real(M_PI/2.0); //1.57079632679489661923      //90
//----------------------------------------------------------------------------------------------------------------------
/// @brief  pre-compute the value for value for PI/4.0
//----------------------------------------------------------------------------------------------------------------------
const static Real PI4=Real(M_PI/4.0); //0.785398163397448309615     //45
//----------------------------------------------------------------------------------------------------------------------
/// @brief calculates the normal from 3 points and return the new normal as a Vector
/// @param[in]  _p1 the first point
/// @param[in]  _p2 the second point
/// @param[in]  _p3 the third point
/// @returns  the normal of the 3 points
//----------------------------------------------------------------------------------------------------------------------
extern NGL_DLLEXPORT glm::vec3 calcNormal( const glm::vec4 &_p1, const glm::vec4 &_p2,   const glm::vec4 &_p3   ) noexcept;
//----------------------------------------------------------------------------------------------------------------------
/// @brief calculates the normal from 3 points and return the new normal as a Vector
/// @param[in]  _p1 the first point
/// @param[in]  _p2 the second point
/// @param[in]  _p3 the third point
/// @returns  the normal of the 3 points
//----------------------------------------------------------------------------------------------------------------------
extern NGL_DLLEXPORT glm::vec3 calcNormal( const glm::vec3 &_p1,  const glm::vec3 &_p2, const glm::vec3 &_p3  ) noexcept;
//----------------------------------------------------------------------------------------------------------------------
/// @brief computer a perspective projection matrix similar to the one from the GLM library
/// this is to help make prorting glm code easier http://glm.g-truc.net/
/// @param[in]  _fovy the fov of the camera frustrum
/// @param[in] _aspect the aspect ratio of the screen
/// @param[in] _zNear the near plane for projection
/// @param[in] _zFar the far plane for the projection
//----------------------------------------------------------------------------------------------------------------------

NGL_DLLEXPORT  glm::mat4 perspective(Real _fovy,Real  _aspect, Real   _zNear, Real   _zFar) noexcept;

//----------------------------------------------------------------------------------------------------------------------
/// @brief computer a perspective projection matrix similar to the one from the GLM library
/// this is to help make prorting glm code easier http://glm.g-truc.net/
/// @param[in]  _fov the fov of the camera frustrum
/// @param[in] _width the width of the screen
/// @param[in] _height the height of the screen
/// @param[in] _zNear the near plane for projection
/// @param[in] _zFar the far plane for the projection
//----------------------------------------------------------------------------------------------------------------------
NGL_DLLEXPORT glm::mat4 perspectiveFov(Real const & _fov, Real const & _width, Real const & _height, Real const & _zNear, Real const & _zFar) noexcept;
//----------------------------------------------------------------------------------------------------------------------
/// @brief computer a perspective projection matrix similar to the one from the GLM library
/// this is to help make prorting glm code easier http://glm.g-truc.net/
/// @param[in]  _fovy the fov of the camera frustrum
/// @param[in] _aspect the aspect ratio of the screen
/// @param[in] _zNear the near plane for projection
//----------------------------------------------------------------------------------------------------------------------
NGL_DLLEXPORT glm::mat4 infinitePerspective(Real _fovy, Real _aspect, Real _zNear) noexcept;


//----------------------------------------------------------------------------------------------------------------------
/// @brief calculate a look at matrix similar to the one from the GLM library
/// this is to help make porting glm code easier http://glm.g-truc.net/
/// @param[in]  _eye the eye position
/// @param[in] _center where we are looking at
/// @param[in] _up the nominal up direction of the camera
//----------------------------------------------------------------------------------------------------------------------
NGL_DLLEXPORT glm::mat4 lookAt(const glm::vec3  & _eye,const glm::vec3  & _center,const glm::vec3  & _up) noexcept;

//----------------------------------------------------------------------------------------------------------------------
/// @brief calculate an ortho graphic projection at matrix similar to the one from the GLM library
/// this is to help make porting glm code easier http://glm.g-truc.net/
/// @param[in]  _left the left most value of the projection
/// @param[in]  _right the right most value of the projection
/// @param[in]  _bottom the bottom most value of the projection
/// @param[in]  _top the top most value of the projection
/// @param[in] _zNear the near plane for projection
/// @param[in] _zFar the far plane for the projection
//----------------------------------------------------------------------------------------------------------------------
NGL_DLLEXPORT glm::mat4 ortho(Real _left, Real _right, Real _bottom, Real _top, Real _zNear, Real _zFar) noexcept;

//----------------------------------------------------------------------------------------------------------------------
/// @brief calculate an ortho graphic projection at matrix similar to the one from the GLM library
/// this is to help make porting glm code easier http://glm.g-truc.net/
/// @param[in]  _left the left most value of the projection
/// @param[in]  _right the right most value of the projection
/// @param[in]  _bottom the bottom most value of the projection
/// @param[in]  _top the top most value of the projection
//----------------------------------------------------------------------------------------------------------------------
NGL_DLLEXPORT glm::mat4 ortho(Real _left, Real _right, Real _bottom, Real _top) noexcept;

//----------------------------------------------------------------------------------------------------------------------
/// @brief calculate frustum  matrix similar to the one from the GLM library
/// this is to help make porting glm code easier http://glm.g-truc.net/
/// @param[in]  _left the left most value of the projection
/// @param[in]  _right the right most value of the projection
/// @param[in]  _bottom the bottom most value of the projection
/// @param[in]  _top the top most value of the projection
/// @param[in] _zNear the near plane for projection
/// @param[in] _zFar the far plane for the projection
//----------------------------------------------------------------------------------------------------------------------
NGL_DLLEXPORT glm::mat4 frustum(Real _left, Real _right, Real _bottom, Real _top, Real _nearVal, Real _farVal) noexcept;

//----------------------------------------------------------------------------------------------------------------------
/// @brief converts Degrees to Radians
/// @param[in]  _deg the angle to convert
/// @returns the angle in Radians
//----------------------------------------------------------------------------------------------------------------------
extern NGL_DLLEXPORT Real radians(const Real _deg ) noexcept;
//----------------------------------------------------------------------------------------------------------------------
/// @brief converts Radians to Degrees
/// @param[in]  _rad the angle in radians
/// @returns the angle in Degrees
//----------------------------------------------------------------------------------------------------------------------
extern NGL_DLLEXPORT Real degrees( const Real _rad ) noexcept;

//----------------------------------------------------------------------------------------------------------------------
/// @brief returns if value is a power of 2
/// @param[in]  _x value to check
/// @returns true if a power of 2
//----------------------------------------------------------------------------------------------------------------------
extern NGL_DLLEXPORT bool isPowerOfTwo (unsigned int _x) noexcept;
//----------------------------------------------------------------------------------------------------------------------
/// @brief rounds up the value to next power of 2
/// @param[in]  _x value to round
/// @returns the next pow 2 value
//----------------------------------------------------------------------------------------------------------------------

extern NGL_DLLEXPORT unsigned int nextPow2(unsigned int _x) noexcept;


//----------------------------------------------------------------------------------------------------------------------
/// @brief check for openGL errors and print out.
/// @param[in]  _file the current file where the error occured
/// @param[in]  _line the line number
//----------------------------------------------------------------------------------------------------------------------
extern NGL_DLLEXPORT void NGLCheckGLError(const std::string  &_file, const int _line ) noexcept;
//----------------------------------------------------------------------------------------------------------------------
/// @brief a simple template function for Linear Interpolation requires that any classes have
///    + - and * scalar (i.e. Real) overloaded operators
///    In the graphics lib this will work  for Vector and Colour
/// @param [in] _a the template value for the first parameter
/// @param [in] _b the template value for the first parameter
/// @param [in] _t the value for the blend between _a and _b must be between 0 - 1
//----------------------------------------------------------------------------------------------------------------------
template <class T> T lerp(T _a, T _b, Real _t) noexcept
{
	T p;
	p=_a+(_b-_a)*_t;
	return p;
}

template <class T> T trigInterp(T _a, T _b, Real _t ) noexcept
{
  Real angle=radians(90*_t);
  return _a*cos(angle)*cos(angle)+_b*sin(angle)*sin(angle);
}

template <class T> T cubic( T _a, T _b,Real _t) noexcept
{
  Real v1=(2.0*_t*_t*_t)-3.0*(_t*_t)+1.0;
  Real v2=-(2.0*_t*_t*_t)+3*(_t*_t);
  return (_a*v1)+(_b*v2);
}



}
#endif

//----------------------------------------------------------------------------------------------------------------------
