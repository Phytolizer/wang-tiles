#include "la.h"
#include "stb_image_write.h"

#include <inttypes.h>
#include <iso646.h>
#include <math.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>

#define TILE_WIDTH_PX 128
#define TILE_HEIGHT_PX 128

#define ATLAS_WIDTH_TL 4
#define ATLAS_HEIGHT_TL 4
#define ATLAS_WIDTH_PX (TILE_WIDTH_PX * ATLAS_WIDTH_TL)
#define ATLAS_HEIGHT_PX (TILE_HEIGHT_PX * ATLAS_HEIGHT_TL)

typedef uint8_t bltr_t;
typedef rgb_t frag_shader_t(bltr_t bltr, uv_t uv);
typedef uint32_t rgba32_t;

uint32_t make_rgba32(rgb_t rgb) {
    return (((uint32_t)(rgb.c[COORD_B] * 255.0f) << 16U) bitor
            ((uint32_t)(rgb.c[COORD_G] * 255.0f) << 8U) bitor
            ((uint32_t)(rgb.c[COORD_R] * 255.0f) << 0U) bitor (uint32_t) 0xFF000000U);
}

rgb_t stripes(bltr_t bltr, uv_t uv) {
    (void)bltr;
    const float n = 20.0f;

    vec3f_t v = vec3f(sinf(uv.c[COORD_U] * n), sinf((uv.c[COORD_U] + uv.c[COORD_V]) * n),
            cosf(uv.c[COORD_V] * n));

    return vec3f_mul(vec3f_sum(v, vec3fs(1.0f)), vec3fs(0.5f));
}

rgb_t japan(bltr_t bltr, uv_t uv) {
    (void)bltr;
    float r = 0.25f;
    float a = vec2f_sqrlen(vec2f_sub(vec2fs(0.5f), uv)) > r * r;

    return vec3f(1.0f, a, a);
}

rgb_t wang(bltr_t bltr, uv_t uv) {
    float r = 0.5f;

    // clang-format off
    static const rgb_t colors[] = {
            {{1.0f, 0.0f, 0.0f}},
            {{0.0f, 1.0f, 1.0f}},

            // (rgb_t){{1.0f, 1.0f, 0.0f}},
            // (rgb_t){{0.0f, 0.0f, 1.0f}},

            // (rgb_t){{0.0f, 1.0f, 0.0f}},
            // (rgb_t){{1.0f, 0.0f, 1.0f}},

            // (rgb_t){{0.0f, 0.0f, 0.0f}},
            // (rgb_t){{1.0f, 1.0f, 1.0f}},
    };
    // clang-format on

    static const vec2f_t sides[4] = {
            {{1.0f, 0.5f}},
            {{0.5f, 0.0f}},
            {{0.0f, 0.5f}},
            {{0.5f, 1.0f}},
    };

    rgb_t result = vec3fs(0.0f);
    for (size_t i = 0; i < 4; ++i) {
        vec2f_t p = sides[i];
        float t = 1.0f - fminf(vec2f_len(vec2f_sub(p, uv)) / r, 1.0f);
        rgb_t c = colors[bltr bitand 1];
        result = vec3f_lerp(result, c, vec3fs(t));
        bltr >>= 1;
    }

    result = vec3f_pow(result, vec3fs(1.0f / 2.2f));
    return result;
}

rgb_t wang_0000(uv_t uv) {
    return wang(0x00, uv);
}

void generate_tile32(uint32_t* pixels, size_t width, size_t height, size_t stride, bltr_t bltr,
        frag_shader_t* shader) {
    for (size_t y = 0; y < height; y++) {
        for (size_t x = 0; x < width; x++) {
            float u = (float)x / (float)width;
            float v = (float)y / (float)height;
            rgb_t pixel = shader(bltr, vec2f(u, v));
            pixels[y * stride + x] = make_rgba32(pixel);
        }
    }
}

rgba32_t tile[TILE_WIDTH_PX * TILE_HEIGHT_PX];
rgba32_t atlas[ATLAS_WIDTH_PX * ATLAS_HEIGHT_PX];

int main(void) {
    const char* output_file_path = "output.png";
    for (bltr_t bltr = 0; bltr < 16; bltr++) {
        printf("Generating god seed %2" PRIu8 "...\n", bltr);
        size_t row = (bltr / ATLAS_WIDTH_TL) * TILE_HEIGHT_PX;
        size_t col = (bltr % ATLAS_WIDTH_TL) * TILE_WIDTH_PX;

        generate_tile32(&atlas[row * ATLAS_WIDTH_PX + col], TILE_WIDTH_PX, TILE_HEIGHT_PX,
                ATLAS_WIDTH_PX, bltr, wang);
    }
    if (!stbi_write_png(output_file_path, ATLAS_WIDTH_PX, ATLAS_HEIGHT_PX, 4, atlas,
                ATLAS_WIDTH_PX * sizeof(rgba32_t))) {
        fprintf(stderr, "Could not save %s\n", output_file_path);
        return 1;
    }
}
