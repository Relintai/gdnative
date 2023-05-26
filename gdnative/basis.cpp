/**************************************************************************/
/*  basis.cpp                                                             */
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

#include "gdn/basis.h"

#include "core/math/basis.h"
#include "core/variant/variant.h"

#ifdef __cplusplus
extern "C" {
#endif

static_assert(sizeof(pandemonium_basis) == sizeof(Basis), "Basis size mismatch");

void GDAPI pandemonium_basis_new_with_rows(pandemonium_basis *r_dest, const pandemonium_vector3 *p_x_axis, const pandemonium_vector3 *p_y_axis, const pandemonium_vector3 *p_z_axis) {
	const Vector3 *x_axis = (const Vector3 *)p_x_axis;
	const Vector3 *y_axis = (const Vector3 *)p_y_axis;
	const Vector3 *z_axis = (const Vector3 *)p_z_axis;
	Basis *dest = (Basis *)r_dest;
	*dest = Basis(*x_axis, *y_axis, *z_axis);
}

void GDAPI pandemonium_basis_new_with_axis_and_angle(pandemonium_basis *r_dest, const pandemonium_vector3 *p_axis, const pandemonium_real p_phi) {
	const Vector3 *axis = (const Vector3 *)p_axis;
	Basis *dest = (Basis *)r_dest;
	*dest = Basis(*axis, p_phi);
}

void GDAPI pandemonium_basis_new_with_euler(pandemonium_basis *r_dest, const pandemonium_vector3 *p_euler) {
	const Vector3 *euler = (const Vector3 *)p_euler;
	Basis *dest = (Basis *)r_dest;
	*dest = Basis(*euler);
}

pandemonium_string GDAPI pandemonium_basis_as_string(const pandemonium_basis *p_self) {
	pandemonium_string ret;
	const Basis *self = (const Basis *)p_self;
	memnew_placement(&ret, String(*self));
	return ret;
}

pandemonium_basis GDAPI pandemonium_basis_inverse(const pandemonium_basis *p_self) {
	pandemonium_basis dest;
	const Basis *self = (const Basis *)p_self;
	*((Basis *)&dest) = self->inverse();
	return dest;
}

pandemonium_basis GDAPI pandemonium_basis_transposed(const pandemonium_basis *p_self) {
	pandemonium_basis dest;
	const Basis *self = (const Basis *)p_self;
	*((Basis *)&dest) = self->transposed();
	return dest;
}

pandemonium_basis GDAPI pandemonium_basis_orthonormalized(const pandemonium_basis *p_self) {
	pandemonium_basis dest;
	const Basis *self = (const Basis *)p_self;
	*((Basis *)&dest) = self->orthonormalized();
	return dest;
}

pandemonium_real GDAPI pandemonium_basis_determinant(const pandemonium_basis *p_self) {
	const Basis *self = (const Basis *)p_self;
	return self->determinant();
}

pandemonium_basis GDAPI pandemonium_basis_rotated(const pandemonium_basis *p_self, const pandemonium_vector3 *p_axis, const pandemonium_real p_phi) {
	pandemonium_basis dest;
	const Basis *self = (const Basis *)p_self;
	const Vector3 *axis = (const Vector3 *)p_axis;
	*((Basis *)&dest) = self->rotated(*axis, p_phi);
	return dest;
}

pandemonium_basis GDAPI pandemonium_basis_scaled(const pandemonium_basis *p_self, const pandemonium_vector3 *p_scale) {
	pandemonium_basis dest;
	const Basis *self = (const Basis *)p_self;
	const Vector3 *scale = (const Vector3 *)p_scale;
	*((Basis *)&dest) = self->scaled(*scale);
	return dest;
}

pandemonium_vector3 GDAPI pandemonium_basis_get_scale(const pandemonium_basis *p_self) {
	pandemonium_vector3 dest;
	const Basis *self = (const Basis *)p_self;
	*((Vector3 *)&dest) = self->get_scale();
	return dest;
}

pandemonium_quaternion GDAPI pandemonium_basis_get_quaternion(const pandemonium_basis *p_self) {
	pandemonium_quaternion dest;
	const Basis *self = (const Basis *)p_self;
	*((Quaternion *)&dest) = self->get_quaternion();
	return dest;
}

void GDAPI pandemonium_basis_set_quaternion(pandemonium_basis *p_self, const pandemonium_quaternion *p_quaternion) {
	Basis *self = (Basis *)p_self;
	const Quaternion *quaternion = (const Quaternion *)p_quaternion;
	self->set_quaternion(*quaternion);
}

void GDAPI pandemonium_basis_set_axis_angle_scale(pandemonium_basis *p_self, const pandemonium_vector3 *p_axis, pandemonium_real p_phi, const pandemonium_vector3 *p_scale) {
	Basis *self = (Basis *)p_self;
	const Vector3 *axis = (const Vector3 *)p_axis;
	const Vector3 *scale = (const Vector3 *)p_scale;
	self->set_axis_angle_scale(*axis, p_phi, *scale);
}

void GDAPI pandemonium_basis_set_euler_scale(pandemonium_basis *p_self, const pandemonium_vector3 *p_euler, const pandemonium_vector3 *p_scale) {
	Basis *self = (Basis *)p_self;
	const Vector3 *euler = (const Vector3 *)p_euler;
	const Vector3 *scale = (const Vector3 *)p_scale;
	self->set_euler_scale(*euler, *scale);
}

void GDAPI pandemonium_basis_set_quaternion_scale(pandemonium_basis *p_self, const pandemonium_quaternion *p_quaternion, const pandemonium_vector3 *p_scale) {
	Basis *self = (Basis *)p_self;
	const Quaternion *quaternion = (const Quaternion *)p_quaternion;
	const Vector3 *scale = (const Vector3 *)p_scale;
	self->set_quaternion_scale(*quaternion, *scale);
}

pandemonium_vector3 GDAPI pandemonium_basis_get_euler(const pandemonium_basis *p_self) {
	pandemonium_vector3 dest;
	const Basis *self = (const Basis *)p_self;
	*((Vector3 *)&dest) = self->get_euler();
	return dest;
}

pandemonium_real GDAPI pandemonium_basis_tdotx(const pandemonium_basis *p_self, const pandemonium_vector3 *p_with) {
	const Basis *self = (const Basis *)p_self;
	const Vector3 *with = (const Vector3 *)p_with;
	return self->tdotx(*with);
}

pandemonium_real GDAPI pandemonium_basis_tdoty(const pandemonium_basis *p_self, const pandemonium_vector3 *p_with) {
	const Basis *self = (const Basis *)p_self;
	const Vector3 *with = (const Vector3 *)p_with;
	return self->tdoty(*with);
}

pandemonium_real GDAPI pandemonium_basis_tdotz(const pandemonium_basis *p_self, const pandemonium_vector3 *p_with) {
	const Basis *self = (const Basis *)p_self;
	const Vector3 *with = (const Vector3 *)p_with;
	return self->tdotz(*with);
}

pandemonium_vector3 GDAPI pandemonium_basis_xform(const pandemonium_basis *p_self, const pandemonium_vector3 *p_v) {
	pandemonium_vector3 dest;
	const Basis *self = (const Basis *)p_self;
	const Vector3 *v = (const Vector3 *)p_v;
	*((Vector3 *)&dest) = self->xform(*v);
	return dest;
}

pandemonium_vector3 GDAPI pandemonium_basis_xform_inv(const pandemonium_basis *p_self, const pandemonium_vector3 *p_v) {
	pandemonium_vector3 dest;
	const Basis *self = (const Basis *)p_self;
	const Vector3 *v = (const Vector3 *)p_v;
	*((Vector3 *)&dest) = self->xform_inv(*v);
	return dest;
}

pandemonium_int GDAPI pandemonium_basis_get_orthogonal_index(const pandemonium_basis *p_self) {
	const Basis *self = (const Basis *)p_self;
	return self->get_orthogonal_index();
}

void GDAPI pandemonium_basis_new(pandemonium_basis *r_dest) {
	Basis *dest = (Basis *)r_dest;
	*dest = Basis();
}

void GDAPI pandemonium_basis_new_with_euler_quaternion(pandemonium_basis *r_dest, const pandemonium_quaternion *p_euler) {
	Basis *dest = (Basis *)r_dest;
	const Quaternion *euler = (const Quaternion *)p_euler;
	*dest = Basis(*euler);
}

// p_elements is a pointer to an array of 3 (!!) vector3
void GDAPI pandemonium_basis_get_elements(const pandemonium_basis *p_self, pandemonium_vector3 *p_elements) {
	const Basis *self = (const Basis *)p_self;
	Vector3 *elements = (Vector3 *)p_elements;
	elements[0] = self->rows[0];
	elements[1] = self->rows[1];
	elements[2] = self->rows[2];
}

pandemonium_vector3 GDAPI pandemonium_basis_get_axis(const pandemonium_basis *p_self, const pandemonium_int p_axis) {
	pandemonium_vector3 dest;
	Vector3 *d = (Vector3 *)&dest;
	const Basis *self = (const Basis *)p_self;
	*d = self->get_axis(p_axis);
	return dest;
}

void GDAPI pandemonium_basis_set_axis(pandemonium_basis *p_self, const pandemonium_int p_axis, const pandemonium_vector3 *p_value) {
	Basis *self = (Basis *)p_self;
	const Vector3 *value = (const Vector3 *)p_value;
	self->set_axis(p_axis, *value);
}

pandemonium_vector3 GDAPI pandemonium_basis_get_row(const pandemonium_basis *p_self, const pandemonium_int p_row) {
	pandemonium_vector3 dest;
	Vector3 *d = (Vector3 *)&dest;
	const Basis *self = (const Basis *)p_self;
	*d = self->get_row(p_row);
	return dest;
}

void GDAPI pandemonium_basis_set_row(pandemonium_basis *p_self, const pandemonium_int p_row, const pandemonium_vector3 *p_value) {
	Basis *self = (Basis *)p_self;
	const Vector3 *value = (const Vector3 *)p_value;
	self->set_row(p_row, *value);
}

pandemonium_bool GDAPI pandemonium_basis_operator_equal(const pandemonium_basis *p_self, const pandemonium_basis *p_b) {
	const Basis *self = (const Basis *)p_self;
	const Basis *b = (const Basis *)p_b;
	return *self == *b;
}

pandemonium_basis GDAPI pandemonium_basis_operator_add(const pandemonium_basis *p_self, const pandemonium_basis *p_b) {
	pandemonium_basis raw_dest;
	Basis *dest = (Basis *)&raw_dest;
	const Basis *self = (const Basis *)p_self;
	const Basis *b = (const Basis *)p_b;
	*dest = *self + *b;
	return raw_dest;
}

pandemonium_basis GDAPI pandemonium_basis_operator_subtract(const pandemonium_basis *p_self, const pandemonium_basis *p_b) {
	pandemonium_basis raw_dest;
	Basis *dest = (Basis *)&raw_dest;
	const Basis *self = (const Basis *)p_self;
	const Basis *b = (const Basis *)p_b;
	*dest = *self - *b;
	return raw_dest;
}

pandemonium_basis GDAPI pandemonium_basis_operator_multiply_vector(const pandemonium_basis *p_self, const pandemonium_basis *p_b) {
	pandemonium_basis raw_dest;
	Basis *dest = (Basis *)&raw_dest;
	const Basis *self = (const Basis *)p_self;
	const Basis *b = (const Basis *)p_b;
	*dest = *self * *b;
	return raw_dest;
}

pandemonium_basis GDAPI pandemonium_basis_operator_multiply_scalar(const pandemonium_basis *p_self, const pandemonium_real p_b) {
	pandemonium_basis raw_dest;
	Basis *dest = (Basis *)&raw_dest;
	const Basis *self = (const Basis *)p_self;
	*dest = *self * p_b;
	return raw_dest;
}

pandemonium_basis GDAPI pandemonium_basis_slerp(const pandemonium_basis *p_self, const pandemonium_basis *p_b, const pandemonium_real p_t) {
	pandemonium_basis raw_dest;
	Basis *dest = (Basis *)&raw_dest;
	const Basis *self = (const Basis *)p_self;
	const Basis *b = (const Basis *)p_b;
	*dest = self->slerp(*b, p_t);
	return raw_dest;
}

#ifdef __cplusplus
}
#endif
