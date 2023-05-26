/**************************************************************************/
/*  transform.h                                                           */
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

#ifndef GDNATIVE_TRANSFORM_H
#define GDNATIVE_TRANSFORM_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#define PANDEMONIUM_TRANSFORM_SIZE 48

#ifndef PANDEMONIUM_CORE_API_PANDEMONIUM_TRANSFORM_TYPE_DEFINED
#define PANDEMONIUM_CORE_API_PANDEMONIUM_TRANSFORM_TYPE_DEFINED
typedef struct {
	uint8_t _dont_touch_that[PANDEMONIUM_TRANSFORM_SIZE];
} pandemonium_transform;
#endif

// reduce extern "C" nesting for VS2013
#ifdef __cplusplus
}
#endif

#include <gdn/basis.h>
#include <gdn/gdnative.h>
#include <gdn/variant.h>
#include <gdn/vector3.h>

#ifdef __cplusplus
extern "C" {
#endif

void GDAPI pandemonium_transform_new_with_axis_origin(pandemonium_transform *r_dest, const pandemonium_vector3 *p_x_axis, const pandemonium_vector3 *p_y_axis, const pandemonium_vector3 *p_z_axis, const pandemonium_vector3 *p_origin);
void GDAPI pandemonium_transform_new(pandemonium_transform *r_dest, const pandemonium_basis *p_basis, const pandemonium_vector3 *p_origin);
void GDAPI pandemonium_transform_new_with_quaternion(pandemonium_transform *r_dest, const pandemonium_quaternion *p_quaternion);

pandemonium_basis GDAPI pandemonium_transform_get_basis(const pandemonium_transform *p_self);
void GDAPI pandemonium_transform_set_basis(pandemonium_transform *p_self, const pandemonium_basis *p_v);

pandemonium_vector3 GDAPI pandemonium_transform_get_origin(const pandemonium_transform *p_self);
void GDAPI pandemonium_transform_set_origin(pandemonium_transform *p_self, const pandemonium_vector3 *p_v);

pandemonium_string GDAPI pandemonium_transform_as_string(const pandemonium_transform *p_self);

pandemonium_transform GDAPI pandemonium_transform_inverse(const pandemonium_transform *p_self);

pandemonium_transform GDAPI pandemonium_transform_affine_inverse(const pandemonium_transform *p_self);

pandemonium_transform GDAPI pandemonium_transform_orthonormalized(const pandemonium_transform *p_self);

pandemonium_transform GDAPI pandemonium_transform_rotated(const pandemonium_transform *p_self, const pandemonium_vector3 *p_axis, const pandemonium_real p_phi);

pandemonium_transform GDAPI pandemonium_transform_scaled(const pandemonium_transform *p_self, const pandemonium_vector3 *p_scale);

pandemonium_transform GDAPI pandemonium_transform_translated(const pandemonium_transform *p_self, const pandemonium_vector3 *p_ofs);

pandemonium_transform GDAPI pandemonium_transform_looking_at(const pandemonium_transform *p_self, const pandemonium_vector3 *p_target, const pandemonium_vector3 *p_up);

pandemonium_plane GDAPI pandemonium_transform_xform_plane(const pandemonium_transform *p_self, const pandemonium_plane *p_v);

pandemonium_plane GDAPI pandemonium_transform_xform_inv_plane(const pandemonium_transform *p_self, const pandemonium_plane *p_v);

void GDAPI pandemonium_transform_new_identity(pandemonium_transform *r_dest);

pandemonium_bool GDAPI pandemonium_transform_operator_equal(const pandemonium_transform *p_self, const pandemonium_transform *p_b);

pandemonium_transform GDAPI pandemonium_transform_operator_multiply(const pandemonium_transform *p_self, const pandemonium_transform *p_b);

pandemonium_vector3 GDAPI pandemonium_transform_xform_vector3(const pandemonium_transform *p_self, const pandemonium_vector3 *p_v);

pandemonium_vector3 GDAPI pandemonium_transform_xform_inv_vector3(const pandemonium_transform *p_self, const pandemonium_vector3 *p_v);

pandemonium_aabb GDAPI pandemonium_transform_xform_aabb(const pandemonium_transform *p_self, const pandemonium_aabb *p_v);

pandemonium_aabb GDAPI pandemonium_transform_xform_inv_aabb(const pandemonium_transform *p_self, const pandemonium_aabb *p_v);

#ifdef __cplusplus
}
#endif

#endif // GDNATIVE_TRANSFORM_H
