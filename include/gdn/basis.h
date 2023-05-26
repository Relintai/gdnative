/**************************************************************************/
/*  basis.h                                                               */
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

#ifndef GDNATIVE_BASIS_H
#define GDNATIVE_BASIS_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#define PANDEMONIUM_BASIS_SIZE 36

#ifndef PANDEMONIUM_CORE_API_PANDEMONIUM_BASIS_TYPE_DEFINED
#define PANDEMONIUM_CORE_API_PANDEMONIUM_BASIS_TYPE_DEFINED
typedef struct {
	uint8_t _dont_touch_that[PANDEMONIUM_BASIS_SIZE];
} pandemonium_basis;
#endif

// reduce extern "C" nesting for VS2013
#ifdef __cplusplus
}
#endif

#include <gdn/gdnative.h>
#include <gdn/quaternion.h>
#include <gdn/vector3.h>

#ifdef __cplusplus
extern "C" {
#endif

void GDAPI pandemonium_basis_new_with_rows(pandemonium_basis *r_dest, const pandemonium_vector3 *p_x_axis, const pandemonium_vector3 *p_y_axis, const pandemonium_vector3 *p_z_axis);
void GDAPI pandemonium_basis_new_with_axis_and_angle(pandemonium_basis *r_dest, const pandemonium_vector3 *p_axis, const pandemonium_real p_phi);
void GDAPI pandemonium_basis_new_with_euler(pandemonium_basis *r_dest, const pandemonium_vector3 *p_euler);
void GDAPI pandemonium_basis_new_with_euler_quaternion(pandemonium_basis *r_dest, const pandemonium_quaternion *p_euler);

pandemonium_string GDAPI pandemonium_basis_as_string(const pandemonium_basis *p_self);

pandemonium_basis GDAPI pandemonium_basis_inverse(const pandemonium_basis *p_self);

pandemonium_basis GDAPI pandemonium_basis_transposed(const pandemonium_basis *p_self);

pandemonium_basis GDAPI pandemonium_basis_orthonormalized(const pandemonium_basis *p_self);

pandemonium_real GDAPI pandemonium_basis_determinant(const pandemonium_basis *p_self);

pandemonium_basis GDAPI pandemonium_basis_rotated(const pandemonium_basis *p_self, const pandemonium_vector3 *p_axis, const pandemonium_real p_phi);

pandemonium_basis GDAPI pandemonium_basis_scaled(const pandemonium_basis *p_self, const pandemonium_vector3 *p_scale);

pandemonium_vector3 GDAPI pandemonium_basis_get_scale(const pandemonium_basis *p_self);

pandemonium_vector3 GDAPI pandemonium_basis_get_euler(const pandemonium_basis *p_self);

pandemonium_quaternion GDAPI pandemonium_basis_get_quaternion(const pandemonium_basis *p_self);

void GDAPI pandemonium_basis_set_quaternion(pandemonium_basis *p_self, const pandemonium_quaternion *p_quaternion);

void GDAPI pandemonium_basis_set_axis_angle_scale(pandemonium_basis *p_self, const pandemonium_vector3 *p_axis, pandemonium_real p_phi, const pandemonium_vector3 *p_scale);

void GDAPI pandemonium_basis_set_euler_scale(pandemonium_basis *p_self, const pandemonium_vector3 *p_euler, const pandemonium_vector3 *p_scale);

void GDAPI pandemonium_basis_set_quaternion_scale(pandemonium_basis *p_self, const pandemonium_quaternion *p_quaternion, const pandemonium_vector3 *p_scale);

pandemonium_real GDAPI pandemonium_basis_tdotx(const pandemonium_basis *p_self, const pandemonium_vector3 *p_with);

pandemonium_real GDAPI pandemonium_basis_tdoty(const pandemonium_basis *p_self, const pandemonium_vector3 *p_with);

pandemonium_real GDAPI pandemonium_basis_tdotz(const pandemonium_basis *p_self, const pandemonium_vector3 *p_with);

pandemonium_vector3 GDAPI pandemonium_basis_xform(const pandemonium_basis *p_self, const pandemonium_vector3 *p_v);

pandemonium_vector3 GDAPI pandemonium_basis_xform_inv(const pandemonium_basis *p_self, const pandemonium_vector3 *p_v);

pandemonium_int GDAPI pandemonium_basis_get_orthogonal_index(const pandemonium_basis *p_self);

void GDAPI pandemonium_basis_new(pandemonium_basis *r_dest);

// p_elements is a pointer to an array of 3 (!!) vector3
void GDAPI pandemonium_basis_get_elements(const pandemonium_basis *p_self, pandemonium_vector3 *p_elements);

pandemonium_vector3 GDAPI pandemonium_basis_get_axis(const pandemonium_basis *p_self, const pandemonium_int p_axis);

void GDAPI pandemonium_basis_set_axis(pandemonium_basis *p_self, const pandemonium_int p_axis, const pandemonium_vector3 *p_value);

pandemonium_vector3 GDAPI pandemonium_basis_get_row(const pandemonium_basis *p_self, const pandemonium_int p_row);

void GDAPI pandemonium_basis_set_row(pandemonium_basis *p_self, const pandemonium_int p_row, const pandemonium_vector3 *p_value);

pandemonium_bool GDAPI pandemonium_basis_operator_equal(const pandemonium_basis *p_self, const pandemonium_basis *p_b);

pandemonium_basis GDAPI pandemonium_basis_operator_add(const pandemonium_basis *p_self, const pandemonium_basis *p_b);

pandemonium_basis GDAPI pandemonium_basis_operator_subtract(const pandemonium_basis *p_self, const pandemonium_basis *p_b);

pandemonium_basis GDAPI pandemonium_basis_operator_multiply_vector(const pandemonium_basis *p_self, const pandemonium_basis *p_b);

pandemonium_basis GDAPI pandemonium_basis_operator_multiply_scalar(const pandemonium_basis *p_self, const pandemonium_real p_b);

pandemonium_basis GDAPI pandemonium_basis_slerp(const pandemonium_basis *p_self, const pandemonium_basis *p_b, const pandemonium_real p_t);

#ifdef __cplusplus
}
#endif

#endif // GDNATIVE_BASIS_H
