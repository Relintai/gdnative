/**************************************************************************/
/*  quaternion.h                                                                */
/**************************************************************************/
/*                         This file is part of:                          */
/*                             GODOT ENGINE                               */
/*                        https://godotengine.org                         */
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

#define GODOT_QUATERNION_SIZE 16

#ifndef GODOT_CORE_API_GODOT_QUATERNION_TYPE_DEFINED
#define GODOT_CORE_API_GODOT_QUATERNION_TYPE_DEFINED
typedef struct {
	uint8_t _dont_touch_that[GODOT_QUATERNION_SIZE];
} godot_quaternion;
#endif

// reduce extern "C" nesting for VS2013
#ifdef __cplusplus
}
#endif

#include <gdnative/gdnative.h>
#include <gdnative/vector3.h>

#ifdef __cplusplus
extern "C" {
#endif

void GDAPI godot_quaternion_new(godot_quaternion *r_dest, const godot_real p_x, const godot_real p_y, const godot_real p_z, const godot_real p_w);
void GDAPI godot_quaternion_new_with_axis_angle(godot_quaternion *r_dest, const godot_vector3 *p_axis, const godot_real p_angle);
void GDAPI godot_quaternion_new_with_basis(godot_quaternion *r_dest, const godot_basis *p_basis);
void GDAPI godot_quaternion_new_with_euler(godot_quaternion *r_dest, const godot_vector3 *p_euler);

godot_real GDAPI godot_quaternion_get_x(const godot_quaternion *p_self);
void GDAPI godot_quaternion_set_x(godot_quaternion *p_self, const godot_real val);

godot_real GDAPI godot_quaternion_get_y(const godot_quaternion *p_self);
void GDAPI godot_quaternion_set_y(godot_quaternion *p_self, const godot_real val);

godot_real GDAPI godot_quaternion_get_z(const godot_quaternion *p_self);
void GDAPI godot_quaternion_set_z(godot_quaternion *p_self, const godot_real val);

godot_real GDAPI godot_quaternion_get_w(const godot_quaternion *p_self);
void GDAPI godot_quaternion_set_w(godot_quaternion *p_self, const godot_real val);

godot_string GDAPI godot_quaternion_as_string(const godot_quaternion *p_self);

godot_real GDAPI godot_quaternion_length(const godot_quaternion *p_self);

godot_real GDAPI godot_quaternion_length_squared(const godot_quaternion *p_self);

godot_quaternion GDAPI godot_quaternion_normalized(const godot_quaternion *p_self);

godot_bool GDAPI godot_quaternion_is_normalized(const godot_quaternion *p_self);

godot_quaternion GDAPI godot_quaternion_inverse(const godot_quaternion *p_self);

godot_real GDAPI godot_quaternion_dot(const godot_quaternion *p_self, const godot_quaternion *p_b);

godot_vector3 GDAPI godot_quaternion_xform(const godot_quaternion *p_self, const godot_vector3 *p_v);

godot_quaternion GDAPI godot_quaternion_slerp(const godot_quaternion *p_self, const godot_quaternion *p_b, const godot_real p_t);

godot_quaternion GDAPI godot_quaternion_slerpni(const godot_quaternion *p_self, const godot_quaternion *p_b, const godot_real p_t);

godot_quaternion GDAPI godot_quaternion_cubic_slerp(const godot_quaternion *p_self, const godot_quaternion *p_b, const godot_quaternion *p_pre_a, const godot_quaternion *p_post_b, const godot_real p_t);

godot_quaternion GDAPI godot_quaternion_operator_multiply(const godot_quaternion *p_self, const godot_real p_b);

godot_quaternion GDAPI godot_quaternion_operator_add(const godot_quaternion *p_self, const godot_quaternion *p_b);

godot_quaternion GDAPI godot_quaternion_operator_subtract(const godot_quaternion *p_self, const godot_quaternion *p_b);

godot_quaternion GDAPI godot_quaternion_operator_divide(const godot_quaternion *p_self, const godot_real p_b);

godot_bool GDAPI godot_quaternion_operator_equal(const godot_quaternion *p_self, const godot_quaternion *p_b);

godot_quaternion GDAPI godot_quaternion_operator_neg(const godot_quaternion *p_self);

void GDAPI godot_quaternion_set_axis_angle(godot_quaternion *p_self, const godot_vector3 *p_axis, const godot_real p_angle);

#ifdef __cplusplus
}
#endif

#endif // GDNATIVE_QUATERNION_H
