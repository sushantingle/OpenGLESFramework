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


#include "GLCore/GLCore.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "GLCore/Utils/Shader.h"
#include "GLCore/Core/Window.h"
#include "GLCore/Utils/AssetManager.h"
#include "source/Application.h"

Application application;

bool setupGraphics(int w, int h) {
    printGLString("Version", GL_VERSION);
    printGLString("Vendor", GL_VENDOR);
    printGLString("Renderer", GL_RENDERER);
    printGLString("Extensions", GL_EXTENSIONS);

    LOGI("setupGraphics(%d, %d)", w, h);
    application.Init(w, h);
    glViewport(0, 0, w, h);
    checkGlError("glViewport");
    return true;
}

void renderFrame() {
    application.Draw();
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
    AAssetManager * assetManager = AAssetManager_fromJava(env, mgr);

    if (assetManager == NULL) {
        LOGE("error loading assetmaanger");
    } else {
        GLCore::Utils::AssetManager::GetInstance().Init(assetManager);
    }
}