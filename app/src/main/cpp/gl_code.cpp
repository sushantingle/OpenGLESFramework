/*
 * Copyright (C) 2009 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

// OpenGL ES 2.0 code



#include <GLES2/gl2.h>
#include <GLES2/gl2ext.h>

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "GLCore/Core/Log.h"
#include "GLCore/Utils/Shader.h"
#include "GLCore/Core/Window.h"

#include <android/asset_manager.h>
#include <android/asset_manager_jni.h>

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

GLuint gvPositionHandle;
GLCore::Utils::Shader* shader;
AAssetManager *assetManager;

const char* ReadFile(const std::string& filePath)
{
    AAsset* asset = AAssetManager_open(assetManager, filePath.c_str(), AASSET_MODE_UNKNOWN);
    if (asset == nullptr)
    {
        LOGE("Could not load vertex shader");
        return nullptr;
    }
    const void* buffer = AAsset_getBuffer(asset);
    if (buffer == nullptr)
    {
        LOGE("could read vertex shader");
        return nullptr;
    }

    return static_cast<const char*>(buffer);
}

bool setupGraphics(int w, int h) {
    printGLString("Version", GL_VERSION);
    printGLString("Vendor", GL_VENDOR);
    printGLString("Renderer", GL_RENDERER);
    printGLString("Extensions", GL_EXTENSIONS);

    LOGI("setupGraphics(%d, %d)", w, h);

    std::string vs = ReadFile("shaders/test.vert");
    std::string fs = ReadFile("shaders/test.frag");

    shader = GLCore::Utils::Shader::FromGLSLTextFiles(vs, fs);
    if (shader == nullptr)
    {
        LOGE("Could not create program.");
        return false;
    }

    gvPositionHandle = glGetAttribLocation(shader->GetRendererID(), "vPosition");
    checkGlError("glGetAttribLocation");
    LOGI("glGetAttribLocation(\"vPosition\") = %d\n",
            gvPositionHandle);

    glViewport(0, 0, w, h);
    checkGlError("glViewport");
    return true;
}

const GLfloat gTriangleVertices[] = { 0.0f, 0.5f, -0.5f, -0.5f,
        0.5f, -0.5f };

void renderFrame() {
    static float grey;
    grey += 0.01f;
    if (grey > 1.0f) {
        grey = 0.0f;
    }
    glClearColor(grey, grey, grey, 1.0f);
    checkGlError("glClearColor");
    glClear( GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
    checkGlError("glClear");

    glUseProgram(shader->GetRendererID());
    checkGlError("glUseProgram");

    glVertexAttribPointer(gvPositionHandle, 2, GL_FLOAT, GL_FALSE, 0, gTriangleVertices);
    checkGlError("glVertexAttribPointer");
    glEnableVertexAttribArray(gvPositionHandle);
    checkGlError("glEnableVertexAttribArray");
    glDrawArrays(GL_TRIANGLES, 0, 3);
    checkGlError("glDrawArrays");
}

extern "C" {
    JNIEXPORT void JNICALL Java_com_example_openglesframework_GL2JNILib_init(JNIEnv * env, jobject obj,  jint width, jint height);
    JNIEXPORT void JNICALL Java_com_example_openglesframework_GL2JNILib_step(JNIEnv * env, jobject obj);
JNIEXPORT void JNICALL
Java_com_example_openglesframework_GL2JNILib_loadAssetManager(JNIEnv *env, jclass clazz,
                                                              jobject mgr);
};

JNIEXPORT void JNICALL Java_com_example_openglesframework_GL2JNILib_init(JNIEnv * env, jobject obj,  jint width, jint height)
{
    setupGraphics(width, height);
}

JNIEXPORT void JNICALL Java_com_example_openglesframework_GL2JNILib_step(JNIEnv * env, jobject obj)
{
    renderFrame();
}

JNIEXPORT void JNICALL
Java_com_example_openglesframework_GL2JNILib_loadAssetManager(JNIEnv *env, jclass clazz,
                                                              jobject mgr) {
    assetManager = AAssetManager_fromJava(env, mgr);
    if (mgr == NULL) {
        LOGE("error loading assetmaanger");
    } else {
        LOGI("loaded assetmanager");
    }
}