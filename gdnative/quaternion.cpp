/**************************************************************************/
/*  quaternion.cpp                                                              */
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

#include "gdn/quaternion.h"

#include "core/math/quaternion.h"
#include "core/variant/variant.h"

#ifdef __cplusplus
extern "C" {
#endif

static_assert(sizeof(pandemonium_quaternion) == sizeof(Quaternion), "Quaternion size mismatch");

pandemonium_real GDAPI pandemonium_quaternion_get_x(const pandemonium_quaternion *p_self) {
	const Quaternion *self = (const Quaternion *)p_self;
	return self->x;
}

void GDAPI pandemonium_quaternion_set_x(pandemonium_quaternion *p_self, const pandemonium_real val) {
	Quaternion *self = (Quaternion *)p_self;
	self->x = val;
}

pandemonium_real GDAPI pandemonium_quaternion_get_y(const pandemonium_quaternion *p_self) {
	const Quaternion *self = (const Quaternion *)p_self;
	return self->y;
}

void GDAPI pandemonium_quaternion_set_y(pandemonium_quaternion *p_self, const pandemonium_real val) {
	Quaternion *self = (Quaternion *)p_self;
	self->y = val;
}

pandemonium_real GDAPI pandemonium_quaternion_get_z(const pandemonium_quaternion *p_self) {
	const Quaternion *self = (const Quaternion *)p_self;
	return self->z;
}

void GDAPI pandemonium_quaternion_set_z(pandemonium_quaternion *p_self, const pandemonium_real val) {
	Quaternion *self = (Quaternion *)p_self;
	self->z = val;
}

pandemonium_real GDAPI pandemonium_quaternion_get_w(const pandemonium_quaternion *p_self) {
	const Quaternion *self = (const Quaternion *)p_self;
	return self->w;
}

void GDAPI pandemonium_quaternion_set_w(pandemonium_quaternion *p_self, const pandemonium_real val) {
	Quaternion *self = (Quaternion *)p_self;
	self->w = val;
}

pandemonium_real GDAPI pandemonium_quaternion_length(const pandemonium_quaternion *p_self) {
	const Quaternion *self = (const Quaternion *)p_self;
	return self->length();
}

pandemonium_real GDAPI pandemonium_quaternion_length_squared(const pandemonium_quaternion *p_self) {
	const Quaternion *self = (const Quaternion *)p_self;
	return self->length_squared();
}

pandemonium_quaternion GDAPI pandemonium_quaternion_normalized(const pandemonium_quaternion *p_self) {
	pandemonium_quaternion dest;
	const Quaternion *self = (const Quaternion *)p_self;
	*((Quaternion *)&dest) = self->normalized();
	return dest;
}

pandemonium_bool GDAPI pandemonium_quaternion_is_normalized(const pandemonium_quaternion *p_self) {
	const Quaternion *self = (const Quaternion *)p_self;
	return self->is_normalized();
}

pandemonium_quaternion GDAPI pandemonium_quaternion_inverse(const pandemonium_quaternion *p_self) {
	pandemonium_quaternion dest;
	const Quaternion *self = (const Quaternion *)p_self;
	*((Quaternion *)&dest) = self->inverse();
	return dest;
}

pandemonium_real GDAPI pandemonium_quaternion_dot(const pandemonium_quaternion *p_self, const pandemonium_quaternion *p_b) {
	const Quaternion *self = (const Quaternion *)p_self;
	const Quaternion *b = (const Quaternion *)p_b;
	return self->dot(*b);
}

pandemonium_vector3 GDAPI pandemonium_quaternion_xform(const pandemonium_quaternion *p_self, const pandemonium_vector3 *p_v) {
	pandemonium_vector3 dest;
	const Quaternion *self = (const Quaternion *)p_self;
	const Vector3 *v = (const Vector3 *)p_v;
	*((Vector3 *)&dest) = self->xform(*v);
	return dest;
}

pandemonium_quaternion GDAPI pandemonium_quaternion_slerp(const pandemonium_quaternion *p_self, const pandemonium_quaternion *p_b, const pandemonium_real p_t) {
	pandemonium_quaternion dest;
	const Quaternion *self = (const Quaternion *)p_self;
	const Quaternion *b = (const Quaternion *)p_b;
	*((Quaternion *)&dest) = self->slerp(*b, p_t);
	return dest;
}

pandemonium_quaternion GDAPI pandemonium_quaternion_slerpni(const pandemonium_quaternion *p_self, const pandemonium_quaternion *p_b, const pandemonium_real p_t) {
	pandemonium_quaternion dest;
	const Quaternion *self = (const Quaternion *)p_self;
	const Quaternion *b = (const Quaternion *)p_b;
	*((Quaternion *)&dest) = self->slerpni(*b, p_t);
	return dest;
}

pandemonium_quaternion GDAPI pandemonium_quaternion_cubic_slerp(const pandemonium_quaternion *p_self, const pandemonium_quaternion *p_b, const pandemonium_quaternion *p_pre_a, const pandemonium_quaternion *p_post_b, const pandemonium_real p_t) {
	pandemonium_quaternion dest;
	const Quaternion *self = (const Quaternion *)p_self;
	const Quaternion *b = (const Quaternion *)p_b;
	const Quaternion *pre_a = (const Quaternion *)p_pre_a;
	const Quaternion *post_b = (const Quaternion *)p_post_b;
	*((Quaternion *)&dest) = self->cubic_slerp(*b, *pre_a, *post_b, p_t);
	return dest;
}

pandemonium_quaternion GDAPI pandemonium_quaternion_operator_multiply(const pandemonium_quaternion *p_self, const pandemonium_real p_b) {
	pandemonium_quaternion raw_dest;
	Quaternion *dest = (Quaternion *)&raw_dest;
	const Quaternion *self = (const Quaternion *)p_self;
	*dest = *self * p_b;
	return raw_dest;
}

pandemonium_quaternion GDAPI pandemonium_quaternion_operator_add(const pandemonium_quaternion *p_self, const pandemonium_quaternion *p_b) {
	pandemonium_quaternion raw_dest;
	Quaternion *dest = (Quaternion *)&raw_dest;
	const Quaternion *self = (const Quaternion *)p_self;
	const Quaternion *b = (const Quaternion *)p_b;
	*dest = *self + *b;
	return raw_dest;
}

pandemonium_quaternion GDAPI pandemonium_quaternion_operator_subtract(const pandemonium_quaternion *p_self, const pandemonium_quaternion *p_b) {
	pandemonium_quaternion raw_dest;
	Quaternion *dest = (Quaternion *)&raw_dest;
	const Quaternion *self = (const Quaternion *)p_self;
	const Quaternion *b = (const Quaternion *)p_b;
	*dest = *self - *b;
	return raw_dest;
}

pandemonium_quaternion GDAPI pandemonium_quaternion_operator_divide(const pandemonium_quaternion *p_self, const pandemonium_real p_b) {
	pandemonium_quaternion raw_dest;
	Quaternion *dest = (Quaternion *)&raw_dest;
	const Quaternion *self = (const Quaternion *)p_self;
	*dest = *self / p_b;
	return raw_dest;
}

pandemonium_bool GDAPI pandemonium_quaternion_operator_equal(const pandemonium_quaternion *p_self, const pandemonium_quaternion *p_b) {
	const Quaternion *self = (const Quaternion *)p_self;
	const Quaternion *b = (const Quaternion *)p_b;
	return *self == *b;
}

pandemonium_quaternion GDAPI pandemonium_quaternion_operator_neg(const pandemonium_quaternion *p_self) {
	pandemonium_quaternion raw_dest;
	Quaternion *dest = (Quaternion *)&raw_dest;
	const Quaternion *self = (const Quaternion *)p_self;
	*dest = -(*self);
	return raw_dest;
}

void GDAPI pandemonium_quaternion_set_axis_angle(pandemonium_quaternion *p_self, const pandemonium_vector3 *p_axis, const pandemonium_real p_angle) {
	Quaternion *self = (Quaternion *)p_self;
	const Vector3 *axis = (const Vector3 *)p_axis;
	self->set_axis_angle(*axis, p_angle);
}

pandemonium_string GDAPI pandemonium_quaternion_as_string(const pandemonium_quaternion *p_self) {
	pandemonium_string ret;
	const Quaternion *self = (const Quaternion *)p_self;
	memnew_placement(&ret, String(*self));
	return ret;
}

void GDAPI pandemonium_quaternion_new(pandemonium_quaternion *r_dest, const pandemonium_real p_x, const pandemonium_real p_y, const pandemonium_real p_z, const pandemonium_real p_w) {
	Quaternion *dest = (Quaternion *)r_dest;
	*dest = Quaternion(p_x, p_y, p_z, p_w);
}

void GDAPI pandemonium_quaternion_new_with_axis_angle(pandemonium_quaternion *r_dest, const pandemonium_vector3 *p_axis, const pandemonium_real p_angle) {
	const Vector3 *axis = (const Vector3 *)p_axis;
	Quaternion *dest = (Quaternion *)r_dest;
	*dest = Quaternion(*axis, p_angle);
}

void GDAPI pandemonium_quaternion_new_with_basis(pandemonium_quaternion *r_dest, const pandemonium_basis *p_basis) {
	const Basis *basis = (const Basis *)p_basis;
	Quaternion *dest = (Quaternion *)r_dest;
	*dest = Quaternion(*basis);
}

void GDAPI pandemonium_quaternion_new_with_euler(pandemonium_quaternion *r_dest, const pandemonium_vector3 *p_euler) {
	const Vector3 *euler = (const Vector3 *)p_euler;
	Quaternion *dest = (Quaternion *)r_dest;
	*dest = Quaternion(*euler);
}

#ifdef __cplusplus
}
#endif