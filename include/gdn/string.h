/**************************************************************************/
/*  string.h                                                              */
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

#ifndef GDNATIVE_STRING_H
#define GDNATIVE_STRING_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
//#include <wchar.h>
#include <uchar.h>

typedef char32_t pandemonium_char_type;

#define PANDEMONIUM_STRING_SIZE sizeof(void *)
#define PANDEMONIUM_CHAR_STRING_SIZE sizeof(void *)

#ifndef PANDEMONIUM_CORE_API_PANDEMONIUM_STRING_TYPE_DEFINED
#define PANDEMONIUM_CORE_API_PANDEMONIUM_STRING_TYPE_DEFINED
typedef struct {
	uint8_t _dont_touch_that[PANDEMONIUM_STRING_SIZE];
} pandemonium_string;

#endif

#ifndef PANDEMONIUM_CORE_API_PANDEMONIUM_CHAR_STRING_TYPE_DEFINED
#define PANDEMONIUM_CORE_API_PANDEMONIUM_CHAR_STRING_TYPE_DEFINED
typedef struct {
	uint8_t _dont_touch_that[PANDEMONIUM_CHAR_STRING_SIZE];
} pandemonium_char_string;
#endif

// reduce extern "C" nesting for VS2013
#ifdef __cplusplus
}
#endif

#include <gdn/array.h>
#include <gdn/gdnative.h>
#include <gdn/variant.h>

#ifdef __cplusplus
extern "C" {
#endif

pandemonium_int GDAPI pandemonium_char_string_length(const pandemonium_char_string *p_cs);
const char GDAPI *pandemonium_char_string_get_data(const pandemonium_char_string *p_cs);
void GDAPI pandemonium_char_string_destroy(pandemonium_char_string *p_cs);

void GDAPI pandemonium_string_new(pandemonium_string *r_dest);
void GDAPI pandemonium_string_new_copy(pandemonium_string *r_dest, const pandemonium_string *p_src);
void GDAPI pandemonium_string_new_with_wide_string(pandemonium_string *r_dest, const wchar_t *p_contents, const int p_size);

const char32_t GDAPI *pandemonium_string_operator_index(pandemonium_string *p_self, const pandemonium_int p_idx);
char32_t GDAPI pandemonium_string_operator_index_const(const pandemonium_string *p_self, const pandemonium_int p_idx);
const char32_t GDAPI *pandemonium_string_wide_str(const pandemonium_string *p_self);

pandemonium_bool GDAPI pandemonium_string_operator_equal(const pandemonium_string *p_self, const pandemonium_string *p_b);
pandemonium_bool GDAPI pandemonium_string_operator_less(const pandemonium_string *p_self, const pandemonium_string *p_b);
pandemonium_string GDAPI pandemonium_string_operator_plus(const pandemonium_string *p_self, const pandemonium_string *p_b);

/* Standard size stuff */

pandemonium_int GDAPI pandemonium_string_length(const pandemonium_string *p_self);

/* Helpers */

signed char GDAPI pandemonium_string_casecmp_to(const pandemonium_string *p_self, const pandemonium_string *p_str);
signed char GDAPI pandemonium_string_nocasecmp_to(const pandemonium_string *p_self, const pandemonium_string *p_str);
signed char GDAPI pandemonium_string_naturalnocasecmp_to(const pandemonium_string *p_self, const pandemonium_string *p_str);

pandemonium_bool GDAPI pandemonium_string_begins_with(const pandemonium_string *p_self, const pandemonium_string *p_string);
pandemonium_bool GDAPI pandemonium_string_begins_with_char_array(const pandemonium_string *p_self, const char *p_char_array);
pandemonium_array GDAPI pandemonium_string_bigrams(const pandemonium_string *p_self);
pandemonium_string GDAPI pandemonium_string_chr(wchar_t p_character);
pandemonium_bool GDAPI pandemonium_string_ends_with(const pandemonium_string *p_self, const pandemonium_string *p_string);
pandemonium_int GDAPI pandemonium_string_count(const pandemonium_string *p_self, pandemonium_string p_what, pandemonium_int p_from, pandemonium_int p_to);
pandemonium_int GDAPI pandemonium_string_countn(const pandemonium_string *p_self, pandemonium_string p_what, pandemonium_int p_from, pandemonium_int p_to);
pandemonium_int GDAPI pandemonium_string_find(const pandemonium_string *p_self, pandemonium_string p_what);
pandemonium_int GDAPI pandemonium_string_find_from(const pandemonium_string *p_self, pandemonium_string p_what, pandemonium_int p_from);
pandemonium_int GDAPI pandemonium_string_findmk(const pandemonium_string *p_self, const pandemonium_array *p_keys);
pandemonium_int GDAPI pandemonium_string_findmk_from(const pandemonium_string *p_self, const pandemonium_array *p_keys, pandemonium_int p_from);
pandemonium_int GDAPI pandemonium_string_findmk_from_in_place(const pandemonium_string *p_self, const pandemonium_array *p_keys, pandemonium_int p_from, pandemonium_int *r_key);
pandemonium_int GDAPI pandemonium_string_findn(const pandemonium_string *p_self, pandemonium_string p_what);
pandemonium_int GDAPI pandemonium_string_findn_from(const pandemonium_string *p_self, pandemonium_string p_what, pandemonium_int p_from);
pandemonium_int GDAPI pandemonium_string_find_last(const pandemonium_string *p_self, pandemonium_string p_what);
pandemonium_string GDAPI pandemonium_string_format(const pandemonium_string *p_self, const pandemonium_variant *p_values);
pandemonium_string GDAPI pandemonium_string_format_with_custom_placeholder(const pandemonium_string *p_self, const pandemonium_variant *p_values, const char *p_placeholder);
pandemonium_string GDAPI pandemonium_string_hex_encode_buffer(const uint8_t *p_buffer, pandemonium_int p_len);
pandemonium_int GDAPI pandemonium_string_hex_to_int(const pandemonium_string *p_self);
pandemonium_int GDAPI pandemonium_string_hex_to_int_without_prefix(const pandemonium_string *p_self);
pandemonium_string GDAPI pandemonium_string_insert(const pandemonium_string *p_self, pandemonium_int p_at_pos, pandemonium_string p_string);
pandemonium_bool GDAPI pandemonium_string_is_numeric(const pandemonium_string *p_self);
pandemonium_bool GDAPI pandemonium_string_is_subsequence_of(const pandemonium_string *p_self, const pandemonium_string *p_string);
pandemonium_bool GDAPI pandemonium_string_is_subsequence_ofi(const pandemonium_string *p_self, const pandemonium_string *p_string);
pandemonium_string GDAPI pandemonium_string_lpad(const pandemonium_string *p_self, pandemonium_int p_min_length);
pandemonium_string GDAPI pandemonium_string_lpad_with_custom_character(const pandemonium_string *p_self, pandemonium_int p_min_length, const pandemonium_string *p_character);
pandemonium_bool GDAPI pandemonium_string_match(const pandemonium_string *p_self, const pandemonium_string *p_wildcard);
pandemonium_bool GDAPI pandemonium_string_matchn(const pandemonium_string *p_self, const pandemonium_string *p_wildcard);
pandemonium_string GDAPI pandemonium_string_md5(const uint8_t *p_md5);
pandemonium_string GDAPI pandemonium_string_num(double p_num);
pandemonium_string GDAPI pandemonium_string_num_int64(int64_t p_num, pandemonium_int p_base);
pandemonium_string GDAPI pandemonium_string_num_int64_capitalized(int64_t p_num, pandemonium_int p_base, pandemonium_bool p_capitalize_hex);
pandemonium_string GDAPI pandemonium_string_num_uint64(uint64_t p_num, pandemonium_int p_base);
pandemonium_string GDAPI pandemonium_string_num_uint64_capitalized(uint64_t p_num, pandemonium_int p_base, pandemonium_bool p_capitalize_hex);
pandemonium_string GDAPI pandemonium_string_num_real(double p_num);
pandemonium_string GDAPI pandemonium_string_num_scientific(double p_num);
pandemonium_string GDAPI pandemonium_string_num_with_decimals(double p_num, pandemonium_int p_decimals);
pandemonium_string GDAPI pandemonium_string_pad_decimals(const pandemonium_string *p_self, pandemonium_int p_digits);
pandemonium_string GDAPI pandemonium_string_pad_zeros(const pandemonium_string *p_self, pandemonium_int p_digits);
pandemonium_string GDAPI pandemonium_string_replace_first(const pandemonium_string *p_self, pandemonium_string p_key, pandemonium_string p_with);
pandemonium_string GDAPI pandemonium_string_replace(const pandemonium_string *p_self, pandemonium_string p_key, pandemonium_string p_with);
pandemonium_string GDAPI pandemonium_string_replacen(const pandemonium_string *p_self, pandemonium_string p_key, pandemonium_string p_with);
pandemonium_int GDAPI pandemonium_string_rfind(const pandemonium_string *p_self, pandemonium_string p_what);
pandemonium_int GDAPI pandemonium_string_rfindn(const pandemonium_string *p_self, pandemonium_string p_what);
pandemonium_int GDAPI pandemonium_string_rfind_from(const pandemonium_string *p_self, pandemonium_string p_what, pandemonium_int p_from);
pandemonium_int GDAPI pandemonium_string_rfindn_from(const pandemonium_string *p_self, pandemonium_string p_what, pandemonium_int p_from);
pandemonium_string GDAPI pandemonium_string_rpad(const pandemonium_string *p_self, pandemonium_int p_min_length);
pandemonium_string GDAPI pandemonium_string_rpad_with_custom_character(const pandemonium_string *p_self, pandemonium_int p_min_length, const pandemonium_string *p_character);
pandemonium_real GDAPI pandemonium_string_similarity(const pandemonium_string *p_self, const pandemonium_string *p_string);
pandemonium_string GDAPI pandemonium_string_sprintf(const pandemonium_string *p_self, const pandemonium_array *p_values, pandemonium_bool *p_error);
pandemonium_string GDAPI pandemonium_string_substr(const pandemonium_string *p_self, pandemonium_int p_from, pandemonium_int p_chars);
double GDAPI pandemonium_string_to_double(const pandemonium_string *p_self);
pandemonium_real GDAPI pandemonium_string_to_float(const pandemonium_string *p_self);
pandemonium_int GDAPI pandemonium_string_to_int(const pandemonium_string *p_self);

pandemonium_string GDAPI pandemonium_string_camelcase_to_underscore(const pandemonium_string *p_self);
pandemonium_string GDAPI pandemonium_string_camelcase_to_underscore_lowercased(const pandemonium_string *p_self);
pandemonium_string GDAPI pandemonium_string_capitalize(const pandemonium_string *p_self);
double GDAPI pandemonium_string_char_to_double(const char *p_what);
pandemonium_int GDAPI pandemonium_string_char_to_int(const char *p_what);
int64_t GDAPI pandemonium_string_wchar_to_int(const wchar_t *p_str);
pandemonium_int GDAPI pandemonium_string_char_to_int_with_len(const char *p_what, pandemonium_int p_len);
int64_t GDAPI pandemonium_string_char_to_int64_with_len(const wchar_t *p_str, int p_len);
int64_t GDAPI pandemonium_string_hex_to_int64(const pandemonium_string *p_self);
int64_t GDAPI pandemonium_string_hex_to_int64_with_prefix(const pandemonium_string *p_self);
int64_t GDAPI pandemonium_string_to_int64(const pandemonium_string *p_self);
double GDAPI pandemonium_string_unicode_char_to_double(const wchar_t *p_str, const wchar_t **r_end);

pandemonium_int GDAPI pandemonium_string_get_slice_count(const pandemonium_string *p_self, pandemonium_string p_splitter);
pandemonium_string GDAPI pandemonium_string_get_slice(const pandemonium_string *p_self, pandemonium_string p_splitter, pandemonium_int p_slice);
pandemonium_string GDAPI pandemonium_string_get_slicec(const pandemonium_string *p_self, wchar_t p_splitter, pandemonium_int p_slice);

pandemonium_array GDAPI pandemonium_string_split(const pandemonium_string *p_self, const pandemonium_string *p_splitter);
pandemonium_array GDAPI pandemonium_string_split_allow_empty(const pandemonium_string *p_self, const pandemonium_string *p_splitter);
pandemonium_array GDAPI pandemonium_string_split_floats(const pandemonium_string *p_self, const pandemonium_string *p_splitter);
pandemonium_array GDAPI pandemonium_string_split_floats_allows_empty(const pandemonium_string *p_self, const pandemonium_string *p_splitter);
pandemonium_array GDAPI pandemonium_string_split_floats_mk(const pandemonium_string *p_self, const pandemonium_array *p_splitters);
pandemonium_array GDAPI pandemonium_string_split_floats_mk_allows_empty(const pandemonium_string *p_self, const pandemonium_array *p_splitters);
pandemonium_array GDAPI pandemonium_string_split_ints(const pandemonium_string *p_self, const pandemonium_string *p_splitter);
pandemonium_array GDAPI pandemonium_string_split_ints_allows_empty(const pandemonium_string *p_self, const pandemonium_string *p_splitter);
pandemonium_array GDAPI pandemonium_string_split_ints_mk(const pandemonium_string *p_self, const pandemonium_array *p_splitters);
pandemonium_array GDAPI pandemonium_string_split_ints_mk_allows_empty(const pandemonium_string *p_self, const pandemonium_array *p_splitters);
pandemonium_array GDAPI pandemonium_string_split_spaces(const pandemonium_string *p_self);

pandemonium_string GDAPI pandemonium_string_join(const pandemonium_string *p_self, const pandemonium_array *p_parts);

wchar_t GDAPI pandemonium_string_char_lowercase(wchar_t p_char);
wchar_t GDAPI pandemonium_string_char_uppercase(wchar_t p_char);
pandemonium_string GDAPI pandemonium_string_to_lower(const pandemonium_string *p_self);
pandemonium_string GDAPI pandemonium_string_to_upper(const pandemonium_string *p_self);

pandemonium_string GDAPI pandemonium_string_get_basename(const pandemonium_string *p_self);
pandemonium_string GDAPI pandemonium_string_get_extension(const pandemonium_string *p_self);
pandemonium_string GDAPI pandemonium_string_left(const pandemonium_string *p_self, pandemonium_int p_pos);
wchar_t GDAPI pandemonium_string_ord_at(const pandemonium_string *p_self, pandemonium_int p_idx);
pandemonium_string GDAPI pandemonium_string_plus_file(const pandemonium_string *p_self, const pandemonium_string *p_file);
pandemonium_string GDAPI pandemonium_string_right(const pandemonium_string *p_self, pandemonium_int p_pos);
pandemonium_string GDAPI pandemonium_string_strip_edges(const pandemonium_string *p_self, pandemonium_bool p_left, pandemonium_bool p_right);
pandemonium_string GDAPI pandemonium_string_strip_escapes(const pandemonium_string *p_self);

void GDAPI pandemonium_string_erase(pandemonium_string *p_self, pandemonium_int p_pos, pandemonium_int p_chars);

pandemonium_char_string GDAPI pandemonium_string_ascii(const pandemonium_string *p_self);
pandemonium_char_string GDAPI pandemonium_string_ascii_extended(const pandemonium_string *p_self);
pandemonium_char_string GDAPI pandemonium_string_utf8(const pandemonium_string *p_self);
pandemonium_bool GDAPI pandemonium_string_parse_utf8(pandemonium_string *p_self, const char *p_utf8);
pandemonium_bool GDAPI pandemonium_string_parse_utf8_with_len(pandemonium_string *p_self, const char *p_utf8, pandemonium_int p_len);
pandemonium_string GDAPI pandemonium_string_chars_to_utf8(const char *p_utf8);
pandemonium_string GDAPI pandemonium_string_chars_to_utf8_with_len(const char *p_utf8, pandemonium_int p_len);

uint32_t GDAPI pandemonium_string_hash(const pandemonium_string *p_self);
uint64_t GDAPI pandemonium_string_hash64(const pandemonium_string *p_self);
uint32_t GDAPI pandemonium_string_hash_chars(const char *p_cstr);
uint32_t GDAPI pandemonium_string_hash_chars_with_len(const char *p_cstr, pandemonium_int p_len);
uint32_t GDAPI pandemonium_string_hash_utf8_chars(const wchar_t *p_str);
uint32_t GDAPI pandemonium_string_hash_utf8_chars_with_len(const wchar_t *p_str, pandemonium_int p_len);
pandemonium_pool_byte_array GDAPI pandemonium_string_md5_buffer(const pandemonium_string *p_self);
pandemonium_string GDAPI pandemonium_string_md5_text(const pandemonium_string *p_self);
pandemonium_pool_byte_array GDAPI pandemonium_string_sha256_buffer(const pandemonium_string *p_self);
pandemonium_string GDAPI pandemonium_string_sha256_text(const pandemonium_string *p_self);

pandemonium_bool pandemonium_string_empty(const pandemonium_string *p_self);

// path functions
pandemonium_string GDAPI pandemonium_string_get_base_dir(const pandemonium_string *p_self);
pandemonium_string GDAPI pandemonium_string_get_file(const pandemonium_string *p_self);
pandemonium_string GDAPI pandemonium_string_humanize_size(uint64_t p_size);
pandemonium_bool GDAPI pandemonium_string_is_abs_path(const pandemonium_string *p_self);
pandemonium_bool GDAPI pandemonium_string_is_rel_path(const pandemonium_string *p_self);
pandemonium_bool GDAPI pandemonium_string_is_resource_file(const pandemonium_string *p_self);
pandemonium_string GDAPI pandemonium_string_path_to(const pandemonium_string *p_self, const pandemonium_string *p_path);
pandemonium_string GDAPI pandemonium_string_path_to_file(const pandemonium_string *p_self, const pandemonium_string *p_path);
pandemonium_string GDAPI pandemonium_string_simplify_path(const pandemonium_string *p_self);

pandemonium_string GDAPI pandemonium_string_c_escape(const pandemonium_string *p_self);
pandemonium_string GDAPI pandemonium_string_c_escape_multiline(const pandemonium_string *p_self);
pandemonium_string GDAPI pandemonium_string_c_unescape(const pandemonium_string *p_self);
pandemonium_string GDAPI pandemonium_string_http_escape(const pandemonium_string *p_self);
pandemonium_string GDAPI pandemonium_string_http_unescape(const pandemonium_string *p_self);
pandemonium_string GDAPI pandemonium_string_json_escape(const pandemonium_string *p_self);
pandemonium_string GDAPI pandemonium_string_word_wrap(const pandemonium_string *p_self, pandemonium_int p_chars_per_line);
pandemonium_string GDAPI pandemonium_string_xml_escape(const pandemonium_string *p_self);
pandemonium_string GDAPI pandemonium_string_xml_escape_with_quotes(const pandemonium_string *p_self);
pandemonium_string GDAPI pandemonium_string_xml_unescape(const pandemonium_string *p_self);

pandemonium_string GDAPI pandemonium_string_percent_decode(const pandemonium_string *p_self);
pandemonium_string GDAPI pandemonium_string_percent_encode(const pandemonium_string *p_self);

pandemonium_bool GDAPI pandemonium_string_is_valid_float(const pandemonium_string *p_self);
pandemonium_bool GDAPI pandemonium_string_is_valid_hex_number(const pandemonium_string *p_self, pandemonium_bool p_with_prefix);
pandemonium_bool GDAPI pandemonium_string_is_valid_html_color(const pandemonium_string *p_self);
pandemonium_bool GDAPI pandemonium_string_is_valid_identifier(const pandemonium_string *p_self);
pandemonium_bool GDAPI pandemonium_string_is_valid_integer(const pandemonium_string *p_self);
pandemonium_bool GDAPI pandemonium_string_is_valid_ip_address(const pandemonium_string *p_self);

pandemonium_string GDAPI pandemonium_string_dedent(const pandemonium_string *p_self);
pandemonium_string GDAPI pandemonium_string_trim_prefix(const pandemonium_string *p_self, const pandemonium_string *p_prefix);
pandemonium_string GDAPI pandemonium_string_trim_suffix(const pandemonium_string *p_self, const pandemonium_string *p_suffix);
pandemonium_string GDAPI pandemonium_string_rstrip(const pandemonium_string *p_self, const pandemonium_string *p_chars);
pandemonium_pool_string_array GDAPI pandemonium_string_rsplit(const pandemonium_string *p_self, const pandemonium_string *p_divisor, const pandemonium_bool p_allow_empty, const pandemonium_int p_maxsplit);

void GDAPI pandemonium_string_destroy(pandemonium_string *p_self);

#ifdef __cplusplus
}
#endif

#endif // GDNATIVE_STRING_H
