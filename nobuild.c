#include "nobuild.h"

#include <stdio.h>

const char* sources[] = {
        "la",
        "stb_image_write",
        "wang",
};

int main(void) {
    MKDIRS("build", "obj");
    FOREACH_ARRAY(const char*, source, sources, {
        CMD("cc", "-c", CONCAT(source, ".c"), "-o", PATH("build", "obj", CONCAT(source, ".o")));
    });
    MKDIRS("build", "bin");
}
