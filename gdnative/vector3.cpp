/**************************************************************************/
/*  vector3.cpp                                                           */
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

#include "gdn/vector3.h"

#include "core/containers/vector.h"
#include "core/variant/variant.h"

#ifdef __cplusplus
extern "C" {
#endif

static_assert(sizeof(pandemonium_vector3) == sizeof(Vector3), "Vector3 size mismatch");

void GDAPI pandemonium_vector3_set_axis(pandemonium_vector3 *p_self, const pandemonium_vector3_axis p_axis, const pandemonium_real p_val) {
	Vector3 *self = (Vector3 *)p_self;
	self->set_axis(p_axis, p_val);
}
pandemonium_real GDAPI pandemonium_vector3_get_axis(const pandemonium_vector3 *p_self, const pandemonium_vector3_axis p_axis) {
	const Vector3 *self = (const Vector3 *)p_self;
	return self->get_axis(p_axis);
}

pandemonium_int GDAPI pandemonium_vector3_min_axis(const pandemonium_vector3 *p_self) {
	const Vector3 *self = (const Vector3 *)p_self;
	return self->min_axis();
}
pandemonium_int GDAPI pandemonium_vector3_max_axis(const pandemonium_vector3 *p_self) {
	const Vector3 *self = (const Vector3 *)p_self;
	return self->max_axis();
}

pandemonium_real GDAPI pandemonium_vector3_length(const pandemonium_vector3 *p_self) {
	const Vector3 *self = (const Vector3 *)p_self;
	return self->length();
}
pandemonium_real GDAPI pandemonium_vector3_length_squared(const pandemonium_vector3 *p_self) {
	const Vector3 *self = (const Vector3 *)p_self;
	return self->length_squared();
}

pandemonium_vector3 GDAPI pandemonium_vector3_normalized(const pandemonium_vector3 *p_self) {
	pandemonium_vector3 dest;
	const Vector3 *self = (const Vector3 *)p_self;
	*((Vector3 *)&dest) = self->normalized();
	return dest;
}
pandemonium_bool GDAPI pandemonium_vector3_is_normalized(const pandemonium_vector3 *p_self) {
	const Vector3 *self = (const Vector3 *)p_self;
	return self->is_normalized();
}
pandemonium_vector3 GDAPI pandemonium_vector3_inverse(const pandemonium_vector3 *p_self) {
	pandemonium_vector3 dest;
	const Vector3 *self = (const Vector3 *)p_self;
	*((Vector3 *)&dest) = self->inverse();
	return dest;
}

pandemonium_vector3 GDAPI pandemonium_vector3_snapped(const pandemonium_vector3 *p_self, const pandemonium_vector3 *p_by) {
	pandemonium_vector3 dest;
	const Vector3 *self = (const Vector3 *)p_self;
	const Vector3 *snap_axis = (const Vector3 *)p_by;

	*((Vector3 *)&dest) = self->snapped(*snap_axis);
	return dest;
}

pandemonium_vector3 GDAPI pandemonium_vector3_rotated(const pandemonium_vector3 *p_self, const pandemonium_vector3 *p_axis, const pandemonium_real p_phi) {
	pandemonium_vector3 dest;
	const Vector3 *self = (const Vector3 *)p_self;
	const Vector3 *axis = (const Vector3 *)p_axis;
	*((Vector3 *)&dest) = self->rotated(*axis, p_phi);
	return dest;
}

pandemonium_vector3 GDAPI pandemonium_vector3_linear_interpolate(const pandemonium_vector3 *p_self, const pandemonium_vector3 *p_b, const pandemonium_real p_t) {
	pandemonium_vector3 dest;
	const Vector3 *self = (const Vector3 *)p_self;
	const Vector3 *b = (const Vector3 *)p_b;
	*((Vector3 *)&dest) = self->linear_interpolate(*b, p_t);
	return dest;
}

pandemonium_vector3 GDAPI pandemonium_vector3_cubic_interpolate(const pandemonium_vector3 *p_self, const pandemonium_vector3 *p_b, const pandemonium_vector3 *p_pre_a, const pandemonium_vector3 *p_post_b, const pandemonium_real p_t) {
	pandemonium_vector3 dest;
	const Vector3 *self = (const Vector3 *)p_self;
	const Vector3 *b = (const Vector3 *)p_b;
	const Vector3 *pre_a = (const Vector3 *)p_pre_a;
	const Vector3 *post_b = (const Vector3 *)p_post_b;
	*((Vector3 *)&dest) = self->cubic_interpolate(*b, *pre_a, *post_b, p_t);
	return dest;
}

pandemonium_vector3 GDAPI pandemonium_vector3_move_toward(const pandemonium_vector3 *p_self, const pandemonium_vector3 *p_to, const pandemonium_real p_delta) {
	pandemonium_vector3 dest;
	const Vector3 *self = (const Vector3 *)p_self;
	const Vector3 *to = (const Vector3 *)p_to;
	*((Vector3 *)&dest) = self->move_toward(*to, p_delta);
	return dest;
}

pandemonium_vector3 GDAPI pandemonium_vector3_cross(const pandemonium_vector3 *p_self, const pandemonium_vector3 *p_b) {
	pandemonium_vector3 dest;
	const Vector3 *self = (const Vector3 *)p_self;
	const Vector3 *b = (const Vector3 *)p_b;
	*((Vector3 *)&dest) = self->cross(*b);
	return dest;
}
pandemonium_real GDAPI pandemonium_vector3_dot(const pandemonium_vector3 *p_self, const pandemonium_vector3 *p_b) {
	const Vector3 *self = (const Vector3 *)p_self;
	const Vector3 *b = (const Vector3 *)p_b;
	return self->dot(*b);
}

pandemonium_basis GDAPI pandemonium_vector3_outer(const pandemonium_vector3 *p_self, const pandemonium_vector3 *p_b) {
	pandemonium_basis dest;
	const Vector3 *self = (const Vector3 *)p_self;
	const Vector3 *b = (const Vector3 *)p_b;
	*((Basis *)&dest) = self->outer(*b);
	return dest;
}

pandemonium_basis GDAPI pandemonium_vector3_to_diagonal_matrix(const pandemonium_vector3 *p_self) {
	pandemonium_basis dest;
	const Vector3 *self = (const Vector3 *)p_self;
	*((Basis *)&dest) = self->to_diagonal_matrix();
	return dest;
}

pandemonium_vector3 GDAPI pandemonium_vector3_abs(const pandemonium_vector3 *p_self) {
	pandemonium_vector3 dest;
	const Vector3 *self = (const Vector3 *)p_self;
	*((Vector3 *)&dest) = self->abs();
	return dest;
}

pandemonium_vector3 GDAPI pandemonium_vector3_floor(const pandemonium_vector3 *p_self) {
	pandemonium_vector3 dest;
	const Vector3 *self = (const Vector3 *)p_self;
	*((Vector3 *)&dest) = self->floor();
	return dest;
}

pandemonium_vector3 GDAPI pandemonium_vector3_ceil(const pandemonium_vector3 *p_self) {
	pandemonium_vector3 dest;
	const Vector3 *self = (const Vector3 *)p_self;
	*((Vector3 *)&dest) = self->ceil();
	return dest;
}

pandemonium_real GDAPI pandemonium_vector3_angle_to(const pandemonium_vector3 *p_self, const pandemonium_vector3 *p_to) {
	const Vector3 *self = (const Vector3 *)p_self;
	const Vector3 *to = (const Vector3 *)p_to;
	return self->angle_to(*to);
}

pandemonium_vector3 GDAPI pandemonium_vector3_direction_to(const pandemonium_vector3 *p_self, const pandemonium_vector3 *p_to) {
	pandemonium_vector3 dest;
	const Vector3 *self = (const Vector3 *)p_self;
	const Vector3 *to = (const Vector3 *)p_to;
	*((Vector3 *)&dest) = self->direction_to(*to);
	return dest;
}

pandemonium_real GDAPI pandemonium_vector3_distance_to(const pandemonium_vector3 *p_self, const pandemonium_vector3 *p_b) {
	const Vector3 *self = (const Vector3 *)p_self;
	const Vector3 *b = (const Vector3 *)p_b;
	return self->distance_to(*b);
}

pandemonium_real GDAPI pandemonium_vector3_distance_squared_to(const pandemonium_vector3 *p_self, const pandemonium_vector3 *p_b) {
	const Vector3 *self = (const Vector3 *)p_self;
	const Vector3 *b = (const Vector3 *)p_b;
	return self->distance_squared_to(*b);
}

pandemonium_vector3 GDAPI pandemonium_vector3_slide(const pandemonium_vector3 *p_self, const pandemonium_vector3 *p_n) {
	pandemonium_vector3 dest;
	const Vector3 *self = (const Vector3 *)p_self;
	const Vector3 *n = (const Vector3 *)p_n;
	*((Vector3 *)&dest) = self->slide(*n);
	return dest;
}

pandemonium_vector3 GDAPI pandemonium_vector3_bounce(const pandemonium_vector3 *p_self, const pandemonium_vector3 *p_n) {
	pandemonium_vector3 dest;
	const Vector3 *self = (const Vector3 *)p_self;
	const Vector3 *n = (const Vector3 *)p_n;
	*((Vector3 *)&dest) = self->bounce(*n);
	return dest;
}

pandemonium_vector3 GDAPI pandemonium_vector3_reflect(const pandemonium_vector3 *p_self, const pandemonium_vector3 *p_n) {
	pandemonium_vector3 dest;
	const Vector3 *self = (const Vector3 *)p_self;
	const Vector3 *n = (const Vector3 *)p_n;
	*((Vector3 *)&dest) = self->reflect(*n);
	return dest;
}

pandemonium_vector3 GDAPI pandemonium_vector3_operator_add(const pandemonium_vector3 *p_self, const pandemonium_vector3 *p_b) {
	pandemonium_vector3 raw_dest;
	Vector3 *dest = (Vector3 *)&raw_dest;
	Vector3 *self = (Vector3 *)p_self;
	const Vector3 *b = (const Vector3 *)p_b;
	*dest = *self + *b;
	return raw_dest;
}

pandemonium_vector3 GDAPI pandemonium_vector3_operator_subtract(const pandemonium_vector3 *p_self, const pandemonium_vector3 *p_b) {
	pandemonium_vector3 raw_dest;
	Vector3 *dest = (Vector3 *)&raw_dest;
	Vector3 *self = (Vector3 *)p_self;
	const Vector3 *b = (const Vector3 *)p_b;
	*dest = *self - *b;
	return raw_dest;
}

pandemonium_vector3 GDAPI pandemonium_vector3_operator_multiply_vector(const pandemonium_vector3 *p_self, const pandemonium_vector3 *p_b) {
	pandemonium_vector3 raw_dest;
	Vector3 *dest = (Vector3 *)&raw_dest;
	Vector3 *self = (Vector3 *)p_self;
	const Vector3 *b = (const Vector3 *)p_b;
	*dest = *self * *b;
	return raw_dest;
}

pandemonium_vector3 GDAPI pandemonium_vector3_operator_multiply_scalar(const pandemonium_vector3 *p_self, const pandemonium_real p_b) {
	pandemonium_vector3 raw_dest;
	Vector3 *dest = (Vector3 *)&raw_dest;
	Vector3 *self = (Vector3 *)p_self;
	*dest = *self * p_b;
	return raw_dest;
}

pandemonium_vector3 GDAPI pandemonium_vector3_operator_divide_vector(const pandemonium_vector3 *p_self, const pandemonium_vector3 *p_b) {
	pandemonium_vector3 raw_dest;
	Vector3 *dest = (Vector3 *)&raw_dest;
	Vector3 *self = (Vector3 *)p_self;
	const Vector3 *b = (const Vector3 *)p_b;
	*dest = *self / *b;
	return raw_dest;
}

pandemonium_vector3 GDAPI pandemonium_vector3_operator_divide_scalar(const pandemonium_vector3 *p_self, const pandemonium_real p_b) {
	pandemonium_vector3 raw_dest;
	Vector3 *dest = (Vector3 *)&raw_dest;
	Vector3 *self = (Vector3 *)p_self;
	*dest = *self / p_b;
	return raw_dest;
}

pandemonium_vector3 GDAPI pandemonium_vector3_operator_neg(const pandemonium_vector3 *p_self) {
	pandemonium_vector3 raw_dest;
	Vector3 *dest = (Vector3 *)&raw_dest;
	const Vector3 *self = (const Vector3 *)p_self;
	*dest = -(*self);
	return raw_dest;
}

pandemonium_bool GDAPI pandemonium_vector3_operator_equal(const pandemonium_vector3 *p_self, const pandemonium_vector3 *p_b) {
	Vector3 *self = (Vector3 *)p_self;
	const Vector3 *b = (const Vector3 *)p_b;
	return *self == *b;
}

pandemonium_bool GDAPI pandemonium_vector3_operator_less(const pandemonium_vector3 *p_self, const pandemonium_vector3 *p_b) {
	Vector3 *self = (Vector3 *)p_self;
	const Vector3 *b = (const Vector3 *)p_b;
	return *self < *b;
}

pandemonium_string GDAPI pandemonium_vector3_as_string(const pandemonium_vector3 *p_self) {
	pandemonium_string ret;
	const Vector3 *self = (const Vector3 *)p_self;
	memnew_placement(&ret, String(*self));
	return ret;
}

void GDAPI pandemonium_vector3_new(pandemonium_vector3 *r_dest, const pandemonium_real p_x, const pandemonium_real p_y, const pandemonium_real p_z) {
	Vector3 *dest = (Vector3 *)r_dest;
	*dest = Vector3(p_x, p_y, p_z);
}

#ifdef __cplusplus
}
#endif
