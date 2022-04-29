#include "./la.c"

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include <stb_image_write.h>
#include <stdbool.h>
#include <stdint.h>

#define TILE_WIDTH_PX 512
#define TILE_HEIGHT_PX 512

#define ATLAS_WIDTH_TL 4
#define ATLAS_HEIGHT_TL 4
#define ATLAS_WIDTH_PX (TILE_WIDTH_PX * ATLAS_WIDTH_TL)
#define ATLAS_HEIGHT_PX (TILE_HEIGHT_PX * ATLAS_HEIGHT_TL)

typedef uint8_t BLTR;
typedef RGB (*FragShader)(BLTR bltr, UV uv);
typedef uint32_t RGBA32;

static RGB stripes(UV uv) {
	const float n = 20.0F;
	Vec3f v = vec3f(sinf(uv.c[C_U] * n), sinf((uv.c[C_U] + uv.c[C_V]) * n), cosf(uv.c[C_V] * n));
	return vec3f_mul(vec3f_sum(v, vec3fs(1.0F)), vec3fs(0.5F));
}

static RGB japan(UV uv) {
	const float r = 0.25F;
	bool a = vec2f_sqrlen(vec2f_sub(vec2fs(0.5F), uv)) > r * r;
	return vec3f(1.0F, (float)a, (float)a);
}

static RGB wang(BLTR bltr, UV uv) {
	const float r = 0.5F;
	const RGB colors[] = {
			{{1.0F, 0.0F, 0.0F}}, {{0.0F, 1.0F, 1.0F}},
			/* {{1.0F, 1.0F, 0.0F}}, {{0.0F, 0.0F, 1.0F}}, */
			/* {{0.0F, 1.0F, 0.0F}}, {{1.0F, 0.0F, 1.0F}}, */
			/* {{0.0F, 0.0F, 0.0F}}, {{1.0F, 1.0F, 1.0F}}, */
	};
	static_assert(sizeof(colors) / sizeof(colors[0]) == 2, "colors array size mismatch");
	const Vec2f sides[] = {
			{{1.0F, 0.5F}},
			{{0.5F, 0.0F}},
			{{0.0F, 0.5F}},
			{{0.5F, 1.0F}},
	};
	static_assert(sizeof(sides) / sizeof(sides[0]) == 4, "sides array size mismatch");

	RGB result = vec3fs(0.0F);
	for (size_t i = 0; i < 4; i++) {
		Vec2f p = sides[i];
		float t = 1.0F - fminf(vec2f_len(vec2f_sub(p, uv)) / r, 1.0F);
		result = vec3f_lerp(result, colors[bltr & 1], vec3fs(t));
		bltr >>= 1;
	}
	return vec3f_pow(result, vec3fs(1.0F / 2.2F));
}

static RGBA32 make_rgba32(float r, float g, float b) {
	return (uint32_t)(r * 255) | (uint32_t)(g * 255) << 8 | (uint32_t)(b * 255) << 16 |
			UINT32_C(0xFF000000);
}

static void generate_image32(uint32_t* pixels, size_t width, size_t height, size_t stride,
		BLTR bltr, FragShader shader) {
	for (size_t y = 0; y < height; y++) {
		for (size_t x = 0; x < width; x++) {
			float u = (float)x / (float)width;
			float v = (float)y / (float)height;
			RGB pixel = shader(bltr, vec2f(u, v));
			pixels[y * stride + x] = make_rgba32(pixel.c[C_R], pixel.c[C_G], pixel.c[C_B]);
		}
	}
}

RGBA32 tile[TILE_WIDTH_PX * TILE_HEIGHT_PX];
RGBA32 atlas[ATLAS_WIDTH_PX * ATLAS_HEIGHT_PX];

int main(void) {
	generate_image32(tile, TILE_WIDTH_PX, TILE_HEIGHT_PX, TILE_WIDTH_PX, 15, wang);
	if (!stbi_write_png("output.png", TILE_WIDTH_PX, TILE_HEIGHT_PX, 4, tile,
				TILE_WIDTH_PX * sizeof(RGBA32))) {
		fprintf(stderr, "Failed to write output.png\n");
		return 1;
	}
}
