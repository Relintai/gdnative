/**************************************************************************/
/*  quaternion.h                                                                */
/**************************************************************************/
/*                         This file is part of:                          */
/*                             PANDEMONIUM ENGINE                               */
/*                        https://pandemoniumengine.org                         */
/**************************************************************************/
/* Copyright (c) 2014-present Godot Engine contributors (see AUTHORS.md). */
/* Copyright (c) 2007-2014 Juan Linietsky, Ariel Manzur.                  */
/*                                                                        */
/* Permission is hereby granted, free of charge, to any person obtaining  */
/* a copy of this software and associated documentation files (the        */
/* "Software"), to deal in the Software without restriction, including    */
/* without limitation the rights to use, copy, modify, merge, publish,    */
/* distribute, sublicense, and/or sell copies of the Software, and to     */
/* permit persons to whom the Software is furnished to do so, subject to  */
/* the following conditions:                                              */
/*                                                                        */
/* The above copyright notice and this permission notice shall be         */
/* included in all copies or substantial portions of the Software.        */
/*                                                                        */
/* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,        */
/* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF     */
/* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. */
/* IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY   */
/* CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,   */
/* TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE      */
/* SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.                 */
/**************************************************************************/

#ifndef GDNATIVE_QUATERNION_H
#define GDNATIVE_QUATERNION_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#define PANDEMONIUM_QUATERNION_SIZE 16

#ifndef PANDEMONIUM_CORE_API_PANDEMONIUM_QUATERNION_TYPE_DEFINED
#define PANDEMONIUM_CORE_API_PANDEMONIUM_QUATERNION_TYPE_DEFINED
typedef struct {
	uint8_t _dont_touch_that[PANDEMONIUM_QUATERNION_SIZE];
} pandemonium_quaternion;
#endif

// reduce extern "C" nesting for VS2013
#ifdef __cplusplus
}
#endif

#include <gdn/gdnative.h>
#include <gdn/vector3.h>

#ifdef __cplusplus
extern "C" {
#endif

pandemonium_real GDAPI pandemonium_quaternion_get_x(const pandemonium_quaternion *p_self);
void GDAPI pandemonium_quaternion_set_x(pandemonium_quaternion *p_self, const pandemonium_real val);

pandemonium_real GDAPI pandemonium_quaternion_get_y(const pandemonium_quaternion *p_self);
void GDAPI pandemonium_quaternion_set_y(pandemonium_quaternion *p_self, const pandemonium_real val);

pandemonium_real GDAPI pandemonium_quaternion_get_z(const pandemonium_quaternion *p_self);
void GDAPI pandemonium_quaternion_set_z(pandemonium_quaternion *p_self, const pandemonium_real val);

pandemonium_real GDAPI pandemonium_quaternion_get_w(const pandemonium_quaternion *p_self);
void GDAPI pandemonium_quaternion_set_w(pandemonium_quaternion *p_self, const pandemonium_real val);

pandemonium_real GDAPI pandemonium_quaternion_length_squared(const pandemonium_quaternion *p_self);
//bool is_equal_approx(const Quaternion &p_quat) const;
pandemonium_real GDAPI pandemonium_quaternion_length(const pandemonium_quaternion *p_self);
//void normalize();
pandemonium_quaternion GDAPI pandemonium_quaternion_normalized(const pandemonium_quaternion *p_self);
pandemonium_bool GDAPI pandemonium_quaternion_is_normalized(const pandemonium_quaternion *p_self);

pandemonium_quaternion GDAPI pandemonium_quaternion_inverse(const pandemonium_quaternion *p_self);
//Quaternion log() const;
//Quaternion exp() const;
pandemonium_real GDAPI pandemonium_quaternion_dot(const pandemonium_quaternion *p_self, const pandemonium_quaternion *p_b);
//real_t angle_to(const Quaternion &p_to) const;

//void set_euler_xyz(const Vector3 &p_euler);
//Vector3 get_euler_xyz() const;
//void set_euler_yxz(const Vector3 &p_euler);
//Vector3 get_euler_yxz() const;

//void set_euler(const Vector3 &p_euler) { set_euler_yxz(p_euler); };
//Vector3 get_euler() const { return get_euler_yxz(); };

pandemonium_quaternion GDAPI pandemonium_quaternion_slerp(const pandemonium_quaternion *p_self, const pandemonium_quaternion *p_b, const pandemonium_real p_t);
pandemonium_quaternion GDAPI pandemonium_quaternion_slerpni(const pandemonium_quaternion *p_self, const pandemonium_quaternion *p_b, const pandemonium_real p_t);
pandemonium_quaternion GDAPI pandemonium_quaternion_cubic_slerp(const pandemonium_quaternion *p_self, const pandemonium_quaternion *p_b, const pandemonium_quaternion *p_pre_a, const pandemonium_quaternion *p_post_b, const pandemonium_real p_t);
//Quaternion spherical_cubic_interpolate(const Quaternion &p_b, const Quaternion &p_pre_a, const Quaternion &p_post_b, const real_t &p_weight) const;

//Vector3 get_axis() const;
//float get_angle() const;

void GDAPI pandemonium_quaternion_set_axis_angle(pandemonium_quaternion *p_self, const pandemonium_vector3 *p_axis, const pandemonium_real p_angle);
//_FORCE_INLINE_ void get_axis_angle(Vector3 &r_axis, real_t &r_angle) const {

//void operator*=(const Quaternion &p_q);

pandemonium_vector3 GDAPI pandemonium_quaternion_xform(const pandemonium_quaternion *p_self, const pandemonium_vector3 *p_v);

pandemonium_quaternion GDAPI pandemonium_quaternion_operator_add(const pandemonium_quaternion *p_self, const pandemonium_quaternion *p_b);
pandemonium_quaternion GDAPI pandemonium_quaternion_operator_subtract(const pandemonium_quaternion *p_self, const pandemonium_quaternion *p_b);

pandemonium_quaternion GDAPI pandemonium_quaternion_operator_multiply(const pandemonium_quaternion *p_self, const pandemonium_real p_b);
pandemonium_quaternion GDAPI pandemonium_quaternion_operator_divide(const pandemonium_quaternion *p_self, const pandemonium_real p_b);

pandemonium_quaternion GDAPI pandemonium_quaternion_operator_neg(const pandemonium_quaternion *p_self);

pandemonium_bool GDAPI pandemonium_quaternion_operator_equal(const pandemonium_quaternion *p_self, const pandemonium_quaternion *p_b);

pandemonium_string GDAPI pandemonium_quaternion_as_string(const pandemonium_quaternion *p_self);

//inline void set(real_t p_x, real_t p_y, real_t p_z, real_t p_w) {

void GDAPI pandemonium_quaternion_new(pandemonium_quaternion *r_dest, const pandemonium_real p_x, const pandemonium_real p_y, const pandemonium_real p_z, const pandemonium_real p_w);
void GDAPI pandemonium_quaternion_new_with_axis_angle(pandemonium_quaternion *r_dest, const pandemonium_vector3 *p_axis, const pandemonium_real p_angle);
void GDAPI pandemonium_quaternion_new_with_basis(pandemonium_quaternion *r_dest, const pandemonium_basis *p_basis);
void GDAPI pandemonium_quaternion_new_with_euler(pandemonium_quaternion *r_dest, const pandemonium_vector3 *p_euler);
//Quaternion(const Vector3 &v0, const Vector3 &v1) // shortest arc

#ifdef __cplusplus
}
#endif

#endif // GDNATIVE_QUATERNION_H
