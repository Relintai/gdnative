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

/*
_FORCE_INLINE_ real_t tdotx(const Vector2 &v) const { return columns[0][0] * v.x + columns[1][0] * v.y; }
_FORCE_INLINE_ real_t tdoty(const Vector2 &v) const { return columns[0][1] * v.x + columns[1][1] * v.y; }

_FORCE_INLINE_ Vector2 get_axis(int p_axis) const {
_FORCE_INLINE_ void set_axis(int p_axis, const Vector2 &p_vec) {

_FORCE_INLINE_ Vector2 get_column(int p_colum) const {
_FORCE_INLINE_ void set_column(int p_colum, const Vector2 &p_vec) {

*/

//void invert();
pandemonium_transform2d GDAPI pandemonium_transform2d_inverse(const pandemonium_transform2d *p_self);

//void affine_invert();
pandemonium_transform2d GDAPI pandemonium_transform2d_affine_inverse(const pandemonium_transform2d *p_self);

//void set_rotation(real_t p_rot);
pandemonium_real GDAPI pandemonium_transform2d_get_rotation(const pandemonium_transform2d *p_self);
//real_t get_skew() const;
//void set_skew(const real_t p_angle);
//_FORCE_INLINE_ void set_rotation_and_scale(real_t p_rot, const Size2 &p_scale);
//_FORCE_INLINE_ void set_rotation_scale_and_skew(const real_t p_rot, const Size2 &p_scale, const real_t p_skew);
//void rotate(real_t p_phi);

//void scale(const Size2 &p_scale);
//void scale_basis(const Size2 &p_scale);
//void translate(real_t p_tx, real_t p_ty);
//void translate(const Vector2 &p_offset);
//void translate_local(real_t p_tx, real_t p_ty);
//void translate_local(const Vector2 &p_translation);

//void translater(real_t p_tx, real_t p_ty);
//void translatev(const Vector2 &p_offset);
//void translate_localr(real_t p_tx, real_t p_ty);
//void translate_localv(const Vector2 &p_translation);

pandemonium_real GDAPI pandemonium_transform2d_basis_determinant(const pandemonium_transform2d *p_self);

pandemonium_vector2 GDAPI pandemonium_transform2d_get_scale(const pandemonium_transform2d *p_self);
//void set_scale(const Size2 &p_scale);

pandemonium_vector2 GDAPI pandemonium_transform2d_get_origin(const pandemonium_transform2d *p_self);
//_FORCE_INLINE_ void set_origin(const Vector2 &p_origin) { columns[2] = p_origin; }

//Transform2D basis_scaled(const Size2 &p_scale) const;
pandemonium_transform2d GDAPI pandemonium_transform2d_scaled(const pandemonium_transform2d *p_self, const pandemonium_vector2 *p_scale);
//Transform2D scaled_local(const Size2 &p_scale) const;
pandemonium_transform2d GDAPI pandemonium_transform2d_translated(const pandemonium_transform2d *p_self, const pandemonium_vector2 *p_offset);
//Transform2D translated_local(const Vector2 &p_offset) const;
pandemonium_transform2d GDAPI pandemonium_transform2d_rotated(const pandemonium_transform2d *p_self, const pandemonium_real p_phi);
//Transform2D rotated_local(const real_t p_angle) const;

//Transform2D untranslated() const;

//void orthonormalize();
pandemonium_transform2d GDAPI pandemonium_transform2d_orthonormalized(const pandemonium_transform2d *p_self);
//bool is_equal_approx(const Transform2D &p_transform) const;

//Transform2D looking_at(const Vector2 &p_target) const;

pandemonium_bool GDAPI pandemonium_transform2d_operator_equal(const pandemonium_transform2d *p_self, const pandemonium_transform2d *p_b);
pandemonium_transform2d GDAPI pandemonium_transform2d_operator_multiply(const pandemonium_transform2d *p_self, const pandemonium_transform2d *p_b);

pandemonium_transform2d GDAPI pandemonium_transform2d_interpolate_with(const pandemonium_transform2d *p_self, const pandemonium_transform2d *p_m, const pandemonium_real p_c);

pandemonium_vector2 GDAPI pandemonium_transform2d_basis_xform_vector2(const pandemonium_transform2d *p_self, const pandemonium_vector2 *p_v);
pandemonium_vector2 GDAPI pandemonium_transform2d_basis_xform_inv_vector2(const pandemonium_transform2d *p_self, const pandemonium_vector2 *p_v);

pandemonium_vector2 GDAPI pandemonium_transform2d_xform_vector2(const pandemonium_transform2d *p_self, const pandemonium_vector2 *p_v);
pandemonium_vector2 GDAPI pandemonium_transform2d_xform_inv_vector2(const pandemonium_transform2d *p_self, const pandemonium_vector2 *p_v);

pandemonium_rect2 GDAPI pandemonium_transform2d_xform_rect2(const pandemonium_transform2d *p_self, const pandemonium_rect2 *p_v);
pandemonium_rect2 GDAPI pandemonium_transform2d_xform_inv_rect2(const pandemonium_transform2d *p_self, const pandemonium_rect2 *p_v);

//_FORCE_INLINE_ Vector2i basis_xform(const Vector2i &p_vec) const;
//_FORCE_INLINE_ Vector2i basis_xform_inv(const Vector2i &p_vec) const;
//_FORCE_INLINE_ Vector2i xform(const Vector2i &p_vec) const;
//_FORCE_INLINE_ Vector2i xform_inv(const Vector2i &p_vec) const;

//_FORCE_INLINE_ PoolVector<Vector2> xform(const PoolVector<Vector2> &p_array) const;
//_FORCE_INLINE_ PoolVector<Vector2> xform_inv(const PoolVector<Vector2> &p_array) const;
//_FORCE_INLINE_ PoolVector<Vector2i> xform(const PoolVector<Vector2i> &p_array) const;
//_FORCE_INLINE_ PoolVector<Vector2i> xform_inv(const PoolVector<Vector2i> &p_array) const;

pandemonium_string GDAPI pandemonium_transform2d_as_string(const pandemonium_transform2d *p_self);

void GDAPI pandemonium_transform2d_new(pandemonium_transform2d *r_dest, const pandemonium_real p_rot, const pandemonium_vector2 *p_pos);
void GDAPI pandemonium_transform2d_new_axis_origin(pandemonium_transform2d *r_dest, const pandemonium_vector2 *p_x_axis, const pandemonium_vector2 *p_y_axis, const pandemonium_vector2 *p_origin);
void GDAPI pandemonium_transform2d_new_identity(pandemonium_transform2d *r_dest);

#ifdef __cplusplus
}
#endif

#endif // GDNATIVE_TRANSFORM2D_H
