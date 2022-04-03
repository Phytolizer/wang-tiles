#pragma once

#define COORD_X 0
#define COORD_Y 1
#define COORD_Z 2
#define COORD_W 3

#define COORD_U 0
#define COORD_V 1

#define COORD_R 0
#define COORD_G 1
#define COORD_B 2
#define COORD_A 3

typedef struct {
    float c[2];
} vec2f_t;

typedef struct {
    float c[3];
} vec3f_t;

typedef struct {
    float c[4];
} vec4f_t;

typedef vec2f_t uv_t;
typedef vec3f_t rgb_t;
typedef vec4f_t rgba_t;

vec2f_t vec2f(float x, float y);
vec2f_t vec2fs(float x);
vec2f_t vec2f_sum(vec2f_t a, vec2f_t b);
vec2f_t vec2f_sub(vec2f_t a, vec2f_t b);
vec2f_t vec2f_mul(vec2f_t a, vec2f_t b);
vec2f_t vec2f_div(vec2f_t a, vec2f_t b);
vec2f_t vec2f_max(vec2f_t a, vec2f_t b);
float vec2f_sqrlen(vec2f_t a);
float vec2f_len(vec2f_t a);
vec2f_t vec2f_lerp(vec2f_t a, vec2f_t b, vec2f_t t);
vec2f_t vec2f_sqrt(vec2f_t a);
vec2f_t vec2f_pow(vec2f_t b, vec2f_t e);

//////////////////////////

vec3f_t vec3f(float x, float y, float z);
vec3f_t vec3fs(float x);
vec3f_t vec3f_sum(vec3f_t a, vec3f_t b);
vec3f_t vec3f_sub(vec3f_t a, vec3f_t b);
vec3f_t vec3f_mul(vec3f_t a, vec3f_t b);
vec3f_t vec3f_div(vec3f_t a, vec3f_t b);
vec3f_t vec3f_max(vec3f_t a, vec3f_t b);
float vec3f_sqrlen(vec3f_t a);
float vec3f_len(vec3f_t a);
vec3f_t vec3f_lerp(vec3f_t a, vec3f_t b, vec3f_t t);
vec3f_t vec3f_sqrt(vec3f_t a);
vec3f_t vec3f_pow(vec3f_t b, vec3f_t e);

//////////////////////////

vec4f_t vec4f(float x, float y, float z, float w);
vec4f_t vec4fs(float x);
vec4f_t vec4f_sum(vec4f_t a, vec4f_t b);
vec4f_t vec4f_sub(vec4f_t a, vec4f_t b);
vec4f_t vec4f_mul(vec4f_t a, vec4f_t b);
vec4f_t vec4f_div(vec4f_t a, vec4f_t b);
vec4f_t vec4f_max(vec4f_t a, vec4f_t b);
float vec4f_sqrlen(vec4f_t a);
float vec4f_len(vec4f_t a);
vec4f_t vec4f_lerp(vec4f_t a, vec4f_t b, vec4f_t t);
vec4f_t vec4f_sqrt(vec4f_t a);
vec4f_t vec4f_pow(vec4f_t b, vec4f_t e);
