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
#define PANDEMONIUM_CHAR_16_STRING_SIZE sizeof(char16_t)

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

#ifndef PANDEMONIUM_CORE_API_PANDEMONIUM_CHAR_16_STRING_TYPE_DEFINED
#define PANDEMONIUM_CORE_API_PANDEMONIUM_CHAR_16_STRING_TYPE_DEFINED
typedef struct {
	uint8_t _dont_touch_that[PANDEMONIUM_CHAR_16_STRING_SIZE];
} pandemonium_char_16_string;
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

//=== Char16String ===

//_FORCE_INLINE_ int size() const { return _cowdata.size(); }
//Error resize(int p_size) {

//_FORCE_INLINE_ char get(int p_index) const { return _cowdata.get(p_index); }
//_FORCE_INLINE_ void set(int p_index, const char &p_elem) { _cowdata.set(p_index, p_elem); }

//_FORCE_INLINE_ void operator=(const CharString &p_str) { _cowdata._ref(p_str._cowdata); }
//void operator=(const char *p_cstr);
//bool operator<(const CharString &p_right) const;
//CharString &operator+=(char p_char);

//pandemonium_int GDAPI pandemonium_char_string_length(const pandemonium_char_string *p_cs);
//const char GDAPI *pandemonium_char_string_get_data(const pandemonium_char_string *p_cs);

//_FORCE_INLINE_ CharString() {}
//_FORCE_INLINE_ CharString(const CharString &p_str) { _cowdata._ref(p_str._cowdata); }
//_FORCE_INLINE_ CharString(const char *p_cstr) { copy_from(p_cstr); }
//void GDAPI pandemonium_char_string_destroy(pandemonium_char_string *p_cs);

//=== CharString ===

//_FORCE_INLINE_ int size() const { return _cowdata.size(); }
//Error resize(int p_size) {

//_FORCE_INLINE_ char get(int p_index) const { return _cowdata.get(p_index); }
//_FORCE_INLINE_ void set(int p_index, const char &p_elem) { _cowdata.set(p_index, p_elem); }

//_FORCE_INLINE_ void operator=(const CharString &p_str) { _cowdata._ref(p_str._cowdata); }
//void operator=(const char *p_cstr);
//bool operator<(const CharString &p_right) const;
//CharString &operator+=(char p_char);

pandemonium_int GDAPI pandemonium_char_string_length(const pandemonium_char_string *p_cs);
const char GDAPI *pandemonium_char_string_get_data(const pandemonium_char_string *p_cs);

//_FORCE_INLINE_ CharString() {}
//_FORCE_INLINE_ CharString(const CharString &p_str) { _cowdata._ref(p_str._cowdata); }
//_FORCE_INLINE_ CharString(const char *p_cstr) { copy_from(p_cstr); }
void GDAPI pandemonium_char_string_destroy(pandemonium_char_string *p_cs);

//=== String ===

//_FORCE_INLINE_ void remove(int p_index) {

//_FORCE_INLINE_ void clear() { resize(0); }

//_FORCE_INLINE_ CharType get(int p_index) const { return _cowdata.get(p_index); }
//_FORCE_INLINE_ void set(int p_index, const CharType &p_elem) { _cowdata.set(p_index, p_elem); }

//_FORCE_INLINE_ int size() const { return _cowdata.size(); }
//_FORCE_INLINE_ Error resize(int p_size) {
//_FORCE_INLINE_ Error set_length(int p_length) { return resize(p_length + 1); }

const char32_t GDAPI *pandemonium_string_operator_index(pandemonium_string *p_self, const pandemonium_int p_idx);
char32_t GDAPI pandemonium_string_operator_index_const(const pandemonium_string *p_self, const pandemonium_int p_idx);

pandemonium_bool GDAPI pandemonium_string_operator_equal(const pandemonium_string *p_self, const pandemonium_string *p_b);
pandemonium_bool GDAPI pandemonium_string_operator_less(const pandemonium_string *p_self, const pandemonium_string *p_b);
pandemonium_string GDAPI pandemonium_string_operator_plus(const pandemonium_string *p_self, const pandemonium_string *p_b);

signed char GDAPI pandemonium_string_casecmp_to(const pandemonium_string *p_self, const pandemonium_string *p_str);
signed char GDAPI pandemonium_string_nocasecmp_to(const pandemonium_string *p_self, const pandemonium_string *p_str);
signed char GDAPI pandemonium_string_naturalnocasecmp_to(const pandemonium_string *p_self, const pandemonium_string *p_str);

//TODO Rename this to get_data
const char32_t GDAPI *pandemonium_string_wide_str(const pandemonium_string *p_self);

pandemonium_int GDAPI pandemonium_string_length(const pandemonium_string *p_self);
//bool is_valid_string() const;

//void print_unicode_error(const String &p_message, bool p_critical = false) const;

pandemonium_string GDAPI pandemonium_string_substr(const pandemonium_string *p_self, pandemonium_int p_from, pandemonium_int p_chars);
//String substr_index(const int p_start_index, const int p_end_index) const; //end_index is not included

pandemonium_int GDAPI pandemonium_string_find(const pandemonium_string *p_self, pandemonium_string p_what);
pandemonium_int GDAPI pandemonium_string_find_from(const pandemonium_string *p_self, pandemonium_string p_what, pandemonium_int p_from);
//int find(const char *p_str, int p_from = 0) const; ///< return <0 if failed
//int find_char(const CharType &p_char, int p_from = 0) const; ///< return <0 if failed
pandemonium_int GDAPI pandemonium_string_find_last(const pandemonium_string *p_self, pandemonium_string p_what);
pandemonium_int GDAPI pandemonium_string_findn(const pandemonium_string *p_self, pandemonium_string p_what);
pandemonium_int GDAPI pandemonium_string_findn_from(const pandemonium_string *p_self, pandemonium_string p_what, pandemonium_int p_from);
pandemonium_int GDAPI pandemonium_string_rfind(const pandemonium_string *p_self, pandemonium_string p_what);
pandemonium_int GDAPI pandemonium_string_rfindn(const pandemonium_string *p_self, pandemonium_string p_what);
pandemonium_int GDAPI pandemonium_string_rfind_from(const pandemonium_string *p_self, pandemonium_string p_what, pandemonium_int p_from);
pandemonium_int GDAPI pandemonium_string_rfindn_from(const pandemonium_string *p_self, pandemonium_string p_what, pandemonium_int p_from);
pandemonium_int GDAPI pandemonium_string_findmk(const pandemonium_string *p_self, const pandemonium_array *p_keys);
pandemonium_int GDAPI pandemonium_string_findmk_from(const pandemonium_string *p_self, const pandemonium_array *p_keys, pandemonium_int p_from);
pandemonium_int GDAPI pandemonium_string_findmk_from_in_place(const pandemonium_string *p_self, const pandemonium_array *p_keys, pandemonium_int p_from, pandemonium_int *r_key);
//int find_first_difference_index(const String &p_str) const;

//bool is_word_at(const int p_index, const char *p_str) const;
//bool is_word_at(const int p_index, const String &p_str) const;

pandemonium_bool GDAPI pandemonium_string_match(const pandemonium_string *p_self, const pandemonium_string *p_wildcard);
pandemonium_bool GDAPI pandemonium_string_matchn(const pandemonium_string *p_self, const pandemonium_string *p_wildcard);

pandemonium_bool GDAPI pandemonium_string_begins_with(const pandemonium_string *p_self, const pandemonium_string *p_string);
pandemonium_bool GDAPI pandemonium_string_begins_with_char_array(const pandemonium_string *p_self, const char *p_char_array);
pandemonium_bool GDAPI pandemonium_string_ends_with(const pandemonium_string *p_self, const pandemonium_string *p_string);

//bool is_enclosed_in(const String &p_string) const;
pandemonium_bool GDAPI pandemonium_string_is_subsequence_of(const pandemonium_string *p_self, const pandemonium_string *p_string);
pandemonium_bool GDAPI pandemonium_string_is_subsequence_ofi(const pandemonium_string *p_self, const pandemonium_string *p_string);
//bool is_quoted() const;

pandemonium_array GDAPI pandemonium_string_bigrams(const pandemonium_string *p_self);
pandemonium_real GDAPI pandemonium_string_similarity(const pandemonium_string *p_self, const pandemonium_string *p_string);
pandemonium_string GDAPI pandemonium_string_format(const pandemonium_string *p_self, const pandemonium_variant *p_values);
pandemonium_string GDAPI pandemonium_string_format_with_custom_placeholder(const pandemonium_string *p_self, const pandemonium_variant *p_values, const char *p_placeholder);

pandemonium_string GDAPI pandemonium_string_replace_first(const pandemonium_string *p_self, pandemonium_string p_key, pandemonium_string p_with);
pandemonium_string GDAPI pandemonium_string_replace(const pandemonium_string *p_self, pandemonium_string p_key, pandemonium_string p_with);
//String replace(const char *p_key, const char *p_with) const;
pandemonium_string GDAPI pandemonium_string_replacen(const pandemonium_string *p_self, pandemonium_string p_key, pandemonium_string p_with);

//String newline_to_br() const;

//String repeat(int p_count) const;
pandemonium_string GDAPI pandemonium_string_insert(const pandemonium_string *p_self, pandemonium_int p_at_pos, pandemonium_string p_string);

pandemonium_string GDAPI pandemonium_string_pad_decimals(const pandemonium_string *p_self, pandemonium_int p_digits);
pandemonium_string GDAPI pandemonium_string_pad_zeros(const pandemonium_string *p_self, pandemonium_int p_digits);

pandemonium_string GDAPI pandemonium_string_trim_prefix(const pandemonium_string *p_self, const pandemonium_string *p_prefix);
pandemonium_string GDAPI pandemonium_string_trim_suffix(const pandemonium_string *p_self, const pandemonium_string *p_suffix);

pandemonium_string GDAPI pandemonium_string_lpad(const pandemonium_string *p_self, pandemonium_int p_min_length);
pandemonium_string GDAPI pandemonium_string_lpad_with_custom_character(const pandemonium_string *p_self, pandemonium_int p_min_length, const pandemonium_string *p_character);
pandemonium_string GDAPI pandemonium_string_rpad(const pandemonium_string *p_self, pandemonium_int p_min_length);
pandemonium_string GDAPI pandemonium_string_rpad_with_custom_character(const pandemonium_string *p_self, pandemonium_int p_min_length, const pandemonium_string *p_character);

pandemonium_string GDAPI pandemonium_string_sprintf(const pandemonium_string *p_self, const pandemonium_array *p_values, pandemonium_bool *p_error);

//String quote(String quotechar = "\"") const;
//String unquote() const;

pandemonium_string GDAPI pandemonium_string_num(double p_num);
pandemonium_string GDAPI pandemonium_string_num_with_decimals(double p_num, pandemonium_int p_decimals);
pandemonium_string GDAPI pandemonium_string_num_scientific(double p_num);
pandemonium_string GDAPI pandemonium_string_num_real(double p_num);
pandemonium_string GDAPI pandemonium_string_num_int64(int64_t p_num, pandemonium_int p_base);
pandemonium_string GDAPI pandemonium_string_num_int64_capitalized(int64_t p_num, pandemonium_int p_base, pandemonium_bool p_capitalize_hex);
pandemonium_string GDAPI pandemonium_string_num_uint64(uint64_t p_num, pandemonium_int p_base);
pandemonium_string GDAPI pandemonium_string_num_uint64_capitalized(uint64_t p_num, pandemonium_int p_base, pandemonium_bool p_capitalize_hex);

pandemonium_string GDAPI pandemonium_string_chr(wchar_t p_character);

pandemonium_string GDAPI pandemonium_string_md5(const uint8_t *p_md5);

pandemonium_string GDAPI pandemonium_string_hex_encode_buffer(const uint8_t *p_buffer, pandemonium_int p_len);

//static String bool_num(bool p_val);
//static String bool_str(bool p_val);

pandemonium_bool GDAPI pandemonium_string_is_numeric(const pandemonium_string *p_self);
//bool is_zero() const;

double GDAPI pandemonium_string_to_double(const pandemonium_string *p_self);
pandemonium_real GDAPI pandemonium_string_to_float(const pandemonium_string *p_self);
pandemonium_int GDAPI pandemonium_string_to_int(const pandemonium_string *p_self);
//bool to_bool() const;
//uint32_t to_uint() const;

pandemonium_int GDAPI pandemonium_string_hex_to_int(const pandemonium_string *p_self);
pandemonium_int GDAPI pandemonium_string_hex_to_int_without_prefix(const pandemonium_string *p_self);
int64_t GDAPI pandemonium_string_hex_to_int64(const pandemonium_string *p_self);
int64_t GDAPI pandemonium_string_hex_to_int64_with_prefix(const pandemonium_string *p_self);
int64_t GDAPI pandemonium_string_to_int64(const pandemonium_string *p_self);

pandemonium_int GDAPI pandemonium_string_char_to_int(const char *p_what);
pandemonium_int GDAPI pandemonium_string_char_to_int_with_len(const char *p_what, pandemonium_int p_len);
int64_t GDAPI pandemonium_string_wchar_to_int(const wchar_t *p_str);
int64_t GDAPI pandemonium_string_char_to_int64_with_len(const wchar_t *p_str, int p_len);
//static int64_t to_int(const CharType *p_str, int p_len = -1, bool p_clamp = false);

//static double to_float(const char *p_str);
//static double to_float(const wchar_t *p_str, const wchar_t **r_end = nullptr);
//static double to_float(const CharType *p_str, const CharType **r_end = nullptr);

double GDAPI pandemonium_string_char_to_double(const char *p_what);
double GDAPI pandemonium_string_unicode_char_to_double(const wchar_t *p_str, const wchar_t **r_end);
//static double to_double(const CharType *p_str, const CharType **r_end = nullptr);

//static uint32_t num_characters(int64_t p_int);

pandemonium_string GDAPI pandemonium_string_capitalize(const pandemonium_string *p_self);
pandemonium_string GDAPI pandemonium_string_camelcase_to_underscore(const pandemonium_string *p_self);
pandemonium_string GDAPI pandemonium_string_camelcase_to_underscore_lowercased(const pandemonium_string *p_self);

//String get_with_code_lines() const;
pandemonium_int GDAPI pandemonium_string_get_slice_count(const pandemonium_string *p_self, pandemonium_string p_splitter);
pandemonium_string GDAPI pandemonium_string_get_slice(const pandemonium_string *p_self, pandemonium_string p_splitter, pandemonium_int p_slice);
pandemonium_string GDAPI pandemonium_string_get_slicec(const pandemonium_string *p_self, wchar_t p_splitter, pandemonium_int p_slice);

pandemonium_array GDAPI pandemonium_string_split(const pandemonium_string *p_self, const pandemonium_string *p_splitter);
pandemonium_array GDAPI pandemonium_string_split_allow_empty(const pandemonium_string *p_self, const pandemonium_string *p_splitter);
//Vector<String> split(const String &p_splitter, bool p_allow_empty = true, int p_maxsplit = 0) const; // p_maxsplit variant
pandemonium_pool_string_array GDAPI pandemonium_string_rsplit(const pandemonium_string *p_self, const pandemonium_string *p_divisor, const pandemonium_bool p_allow_empty, const pandemonium_int p_maxsplit);
//Vector<String> rsplit(const String &p_splitter, bool p_allow_empty = true, int p_maxsplit = 0) const; //p_allow_empty, p_maxsplit variant
pandemonium_array GDAPI pandemonium_string_split_spaces(const pandemonium_string *p_self);
pandemonium_array GDAPI pandemonium_string_split_floats(const pandemonium_string *p_self, const pandemonium_string *p_splitter);
pandemonium_array GDAPI pandemonium_string_split_floats_allows_empty(const pandemonium_string *p_self, const pandemonium_string *p_splitter);
pandemonium_array GDAPI pandemonium_string_split_floats_mk(const pandemonium_string *p_self, const pandemonium_array *p_splitters);
pandemonium_array GDAPI pandemonium_string_split_floats_mk_allows_empty(const pandemonium_string *p_self, const pandemonium_array *p_splitters);
pandemonium_array GDAPI pandemonium_string_split_ints(const pandemonium_string *p_self, const pandemonium_string *p_splitter);
pandemonium_array GDAPI pandemonium_string_split_ints_allows_empty(const pandemonium_string *p_self, const pandemonium_string *p_splitter);
pandemonium_array GDAPI pandemonium_string_split_ints_mk(const pandemonium_string *p_self, const pandemonium_array *p_splitters);
pandemonium_array GDAPI pandemonium_string_split_ints_mk_allows_empty(const pandemonium_string *p_self, const pandemonium_array *p_splitters);

pandemonium_string GDAPI pandemonium_string_join(const pandemonium_string *p_self, const pandemonium_array *p_parts);

wchar_t GDAPI pandemonium_string_char_uppercase(wchar_t p_char); //CharType !
wchar_t GDAPI pandemonium_string_char_lowercase(wchar_t p_char); //CharType !
pandemonium_string GDAPI pandemonium_string_to_upper(const pandemonium_string *p_self);
pandemonium_string GDAPI pandemonium_string_to_lower(const pandemonium_string *p_self);

pandemonium_int GDAPI pandemonium_string_count(const pandemonium_string *p_self, pandemonium_string p_what, pandemonium_int p_from, pandemonium_int p_to);
pandemonium_int GDAPI pandemonium_string_countn(const pandemonium_string *p_self, pandemonium_string p_what, pandemonium_int p_from, pandemonium_int p_to);

pandemonium_string GDAPI pandemonium_string_left(const pandemonium_string *p_self, pandemonium_int p_pos);
pandemonium_string GDAPI pandemonium_string_right(const pandemonium_string *p_self, pandemonium_int p_pos);
//String indent(const String &p_prefix) const;
pandemonium_string GDAPI pandemonium_string_dedent(const pandemonium_string *p_self);

pandemonium_string GDAPI pandemonium_string_strip_edges(const pandemonium_string *p_self, pandemonium_bool p_left, pandemonium_bool p_right); // left, right variant //String strip_edges(bool left = true, bool right = true) const;

pandemonium_string GDAPI pandemonium_string_strip_escapes(const pandemonium_string *p_self);
//String lstrip(const String &p_chars) const;
pandemonium_string GDAPI pandemonium_string_rstrip(const pandemonium_string *p_self, const pandemonium_string *p_chars);

pandemonium_string GDAPI pandemonium_string_get_extension(const pandemonium_string *p_self);
pandemonium_string GDAPI pandemonium_string_get_basename(const pandemonium_string *p_self);
pandemonium_string GDAPI pandemonium_string_plus_file(const pandemonium_string *p_self, const pandemonium_string *p_file);

//CharType unicode_at(int p_idx) const;
wchar_t GDAPI pandemonium_string_ord_at(const pandemonium_string *p_self, pandemonium_int p_idx);

void GDAPI pandemonium_string_erase(pandemonium_string *p_self, pandemonium_int p_pos, pandemonium_int p_chars);

pandemonium_char_string GDAPI pandemonium_string_ascii(const pandemonium_string *p_self);
pandemonium_char_string GDAPI pandemonium_string_ascii_extended(const pandemonium_string *p_self);
pandemonium_char_string GDAPI pandemonium_string_utf8(const pandemonium_string *p_self);
pandemonium_bool GDAPI pandemonium_string_parse_utf8(pandemonium_string *p_self, const char *p_utf8);
pandemonium_bool GDAPI pandemonium_string_parse_utf8_with_len(pandemonium_string *p_self, const char *p_utf8, pandemonium_int p_len); // p_skip_cr variant //Error parse_utf8(const char *p_utf8, int p_len = -1, bool p_skip_cr = false); //return true on error
pandemonium_string GDAPI pandemonium_string_chars_to_utf8(const char *p_utf8);
pandemonium_string GDAPI pandemonium_string_chars_to_utf8_with_len(const char *p_utf8, pandemonium_int p_len);
//int utf8_byte_length() const;

//Char16String utf16() const;
//Error parse_utf16(const char16_t *p_utf16, int p_len = -1);
//static String utf16(const char16_t *p_utf16, int p_len = -1);
//int utf16_byte_length() const;

uint32_t GDAPI pandemonium_string_hash_chars(const char *p_cstr);
uint32_t GDAPI pandemonium_string_hash_chars_with_len(const char *p_cstr, pandemonium_int p_len);
uint32_t GDAPI pandemonium_string_hash_utf8_chars(const wchar_t *p_str); // rename to pandemonium_string_hash_wchars, use its name as the missin?
uint32_t GDAPI pandemonium_string_hash_utf8_chars_with_len(const wchar_t *p_str, pandemonium_int p_len);
//static uint32_t hash(const CharType *p_cstr);
//static uint32_t hash(const CharType *p_cstr, int p_len);

uint32_t GDAPI pandemonium_string_hash(const pandemonium_string *p_self);
uint64_t GDAPI pandemonium_string_hash64(const pandemonium_string *p_self);

pandemonium_string GDAPI pandemonium_string_md5_text(const pandemonium_string *p_self);
//String sha1_text() const;
pandemonium_pool_byte_array GDAPI pandemonium_string_sha256_buffer(const pandemonium_string *p_self);
pandemonium_pool_byte_array GDAPI pandemonium_string_md5_buffer(const pandemonium_string *p_self);
//Vector<uint8_t> sha1_buffer() const;
pandemonium_string GDAPI pandemonium_string_sha256_text(const pandemonium_string *p_self);

pandemonium_bool pandemonium_string_empty(const pandemonium_string *p_self);
//_FORCE_INLINE_ bool contains(const char *p_str) const { return find(p_str) != -1; }
//_FORCE_INLINE_ bool contains(const String &p_str) const { return find(p_str) != -1; }

// path functions

pandemonium_bool GDAPI pandemonium_string_is_abs_path(const pandemonium_string *p_self);
pandemonium_bool GDAPI pandemonium_string_is_rel_path(const pandemonium_string *p_self);
pandemonium_bool GDAPI pandemonium_string_is_resource_file(const pandemonium_string *p_self);
pandemonium_string GDAPI pandemonium_string_path_to(const pandemonium_string *p_self, const pandemonium_string *p_path);
pandemonium_string GDAPI pandemonium_string_path_to_file(const pandemonium_string *p_self, const pandemonium_string *p_path);
pandemonium_string GDAPI pandemonium_string_get_base_dir(const pandemonium_string *p_self);
pandemonium_string GDAPI pandemonium_string_get_file(const pandemonium_string *p_self);
pandemonium_string GDAPI pandemonium_string_humanize_size(uint64_t p_size);
pandemonium_string GDAPI pandemonium_string_simplify_path(const pandemonium_string *p_self);
//bool is_network_share_path() const;
//String append_path(const char *p_path) const;
//String append_path(const String &p_path) const;
//String path_clean_end_slash() const;
//String path_ensure_end_slash() const;
//String path_get_prev_dir() const;

pandemonium_string GDAPI pandemonium_string_xml_escape(const pandemonium_string *p_self);
pandemonium_string GDAPI pandemonium_string_xml_escape_with_quotes(const pandemonium_string *p_self);
pandemonium_string GDAPI pandemonium_string_xml_unescape(const pandemonium_string *p_self);
pandemonium_string GDAPI pandemonium_string_http_escape(const pandemonium_string *p_self);
pandemonium_string GDAPI pandemonium_string_http_unescape(const pandemonium_string *p_self);
//String uri_encode() const;
//String uri_decode() const;
pandemonium_string GDAPI pandemonium_string_c_escape(const pandemonium_string *p_self);
pandemonium_string GDAPI pandemonium_string_c_escape_multiline(const pandemonium_string *p_self);
pandemonium_string GDAPI pandemonium_string_c_unescape(const pandemonium_string *p_self);
pandemonium_string GDAPI pandemonium_string_json_escape(const pandemonium_string *p_self);
pandemonium_string GDAPI pandemonium_string_word_wrap(const pandemonium_string *p_self, pandemonium_int p_chars_per_line);
//Error parse_url(String &r_scheme, String &r_host, int &r_port, String &r_path) const;

pandemonium_string GDAPI pandemonium_string_percent_decode(const pandemonium_string *p_self);
pandemonium_string GDAPI pandemonium_string_percent_encode(const pandemonium_string *p_self);

//String property_name_encode() const;

// node functions
//static String get_invalid_node_name_characters();
//String validate_node_name() const;
//String validate_identifier() const;

pandemonium_bool GDAPI pandemonium_string_is_valid_identifier(const pandemonium_string *p_self);
pandemonium_bool GDAPI pandemonium_string_is_valid_integer(const pandemonium_string *p_self);
pandemonium_bool GDAPI pandemonium_string_is_valid_float(const pandemonium_string *p_self);
pandemonium_bool GDAPI pandemonium_string_is_valid_hex_number(const pandemonium_string *p_self, pandemonium_bool p_with_prefix);
pandemonium_bool GDAPI pandemonium_string_is_valid_html_color(const pandemonium_string *p_self);
pandemonium_bool GDAPI pandemonium_string_is_valid_ip_address(const pandemonium_string *p_self);
//bool is_valid_filename() const;
//bool is_valid_bool() const;
//bool is_valid_unsigned_integer() const;

//Vector<uint8_t> to_ascii_buffer() const;
//Vector<uint8_t> to_utf8_buffer() const;
//Vector<uint8_t> to_utf16_buffer() const;
//Vector<uint8_t> to_utf32_buffer() const;

void GDAPI pandemonium_string_new(pandemonium_string *r_dest);
void GDAPI pandemonium_string_new_copy(pandemonium_string *r_dest, const pandemonium_string *p_src);
void GDAPI pandemonium_string_new_with_wide_string(pandemonium_string *r_dest, const wchar_t *p_contents, const int p_size);
//String(const char *p_str);
//String(const wchar_t *p_str);
//String(const CharType *p_str);
//String(const char *p_str, int p_clip_to_len);
//String(const CharType *p_str, int p_clip_to_len);

void GDAPI pandemonium_string_destroy(pandemonium_string *p_self);

#ifdef __cplusplus
}
#endif

#endif // GDNATIVE_STRING_H
