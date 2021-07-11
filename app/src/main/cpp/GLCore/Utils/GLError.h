//
// Created by Sushant on 11-07-2021.
//

#ifndef OPENGLESFRAMEWORK_GLERROR_H
#define OPENGLESFRAMEWORK_GLERROR_H
#include "../GLCore.h"

static void printGLString(const char *name, GLenum s) {
    const char *v = (const char *) glGetString(s);
    LOGI("GL %s = %s\n", name, v);
}

static void checkGlError(const char* op) {
    for (GLint error = glGetError(); error; error
                                                    = glGetError()) {
        LOGI("after %s() glError (0x%x)\n", op, error);
    }
}

#endif //OPENGLESFRAMEWORK_GLERROR_H
