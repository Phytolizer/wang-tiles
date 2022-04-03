#include "nobuild.h"

#include <stdio.h>

const char* sources[] = {
        "la",
        "stb_image_write",
        "wang",
};

int main(void) {
    MKDIRS("build", "obj");
    const char** objects = malloc(sizeof(char*) * (sizeof sources / sizeof *sources + 1));
    size_t i = 0;
    FOREACH_ARRAY(const char*, source, sources, {
        objects[i] = PATH("build", "obj", CONCAT(source, ".o"));
        CMD("cc", "-c", CONCAT(source, ".c"), "-o", objects[i]);
        i++;
    });
    objects[i] = NULL;
    MKDIRS("build", "bin");
    char** argv = collect_args("vpvvv", "cc", objects, "-lm", "-o", PATH("build", "bin", "wang"));
    echo_cmd(argv);
    nobuild_exec(argv);
}
