/**************************************************************************/
/*  transform2d.h                                                         */
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

#ifndef GDNATIVE_TRANSFORM2D_H
#define GDNATIVE_TRANSFORM2D_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#define PANDEMONIUM_TRANSFORM2D_SIZE 24

#ifndef PANDEMONIUM_CORE_API_PANDEMONIUM_TRANSFORM2D_TYPE_DEFINED
#define PANDEMONIUM_CORE_API_PANDEMONIUM_TRANSFORM2D_TYPE_DEFINED
typedef struct {
	uint8_t _dont_touch_that[PANDEMONIUM_TRANSFORM2D_SIZE];
} pandemonium_transform2d;
#endif

// reduce extern "C" nesting for VS2013
#ifdef __cplusplus
}
#endif

#include <gdn/gdnative.h>
#include <gdn/variant.h>
#include <gdn/vector2.h>

#ifdef __cplusplus
extern "C" {
#endif

void GDAPI pandemonium_transform2d_new(pandemonium_transform2d *r_dest, const pandemonium_real p_rot, const pandemonium_vector2 *p_pos);
void GDAPI pandemonium_transform2d_new_axis_origin(pandemonium_transform2d *r_dest, const pandemonium_vector2 *p_x_axis, const pandemonium_vector2 *p_y_axis, const pandemonium_vector2 *p_origin);

pandemonium_string GDAPI pandemonium_transform2d_as_string(const pandemonium_transform2d *p_self);

pandemonium_transform2d GDAPI pandemonium_transform2d_inverse(const pandemonium_transform2d *p_self);

pandemonium_transform2d GDAPI pandemonium_transform2d_affine_inverse(const pandemonium_transform2d *p_self);

pandemonium_real GDAPI pandemonium_transform2d_get_rotation(const pandemonium_transform2d *p_self);

pandemonium_vector2 GDAPI pandemonium_transform2d_get_origin(const pandemonium_transform2d *p_self);

pandemonium_vector2 GDAPI pandemonium_transform2d_get_scale(const pandemonium_transform2d *p_self);

pandemonium_real GDAPI pandemonium_transform2d_determinant(const pandemonium_transform2d *p_self);

pandemonium_transform2d GDAPI pandemonium_transform2d_orthonormalized(const pandemonium_transform2d *p_self);

pandemonium_transform2d GDAPI pandemonium_transform2d_rotated(const pandemonium_transform2d *p_self, const pandemonium_real p_phi);

pandemonium_transform2d GDAPI pandemonium_transform2d_scaled(const pandemonium_transform2d *p_self, const pandemonium_vector2 *p_scale);

pandemonium_transform2d GDAPI pandemonium_transform2d_translated(const pandemonium_transform2d *p_self, const pandemonium_vector2 *p_offset);

pandemonium_vector2 GDAPI pandemonium_transform2d_xform_vector2(const pandemonium_transform2d *p_self, const pandemonium_vector2 *p_v);

pandemonium_vector2 GDAPI pandemonium_transform2d_xform_inv_vector2(const pandemonium_transform2d *p_self, const pandemonium_vector2 *p_v);

pandemonium_vector2 GDAPI pandemonium_transform2d_basis_xform_vector2(const pandemonium_transform2d *p_self, const pandemonium_vector2 *p_v);

pandemonium_vector2 GDAPI pandemonium_transform2d_basis_xform_inv_vector2(const pandemonium_transform2d *p_self, const pandemonium_vector2 *p_v);

pandemonium_transform2d GDAPI pandemonium_transform2d_interpolate_with(const pandemonium_transform2d *p_self, const pandemonium_transform2d *p_m, const pandemonium_real p_c);

pandemonium_bool GDAPI pandemonium_transform2d_operator_equal(const pandemonium_transform2d *p_self, const pandemonium_transform2d *p_b);

pandemonium_transform2d GDAPI pandemonium_transform2d_operator_multiply(const pandemonium_transform2d *p_self, const pandemonium_transform2d *p_b);

void GDAPI pandemonium_transform2d_new_identity(pandemonium_transform2d *r_dest);

pandemonium_rect2 GDAPI pandemonium_transform2d_xform_rect2(const pandemonium_transform2d *p_self, const pandemonium_rect2 *p_v);

pandemonium_rect2 GDAPI pandemonium_transform2d_xform_inv_rect2(const pandemonium_transform2d *p_self, const pandemonium_rect2 *p_v);

#ifdef __cplusplus
}
#endif

#endif // GDNATIVE_TRANSFORM2D_H
