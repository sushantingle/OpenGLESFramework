//
// Created by Sushant on 10-07-2021.
//

#ifndef OPENGLESFRAMEWORK_LOG_H
#define OPENGLESFRAMEWORK_LOG_H
#include <jni.h>
#include <android/log.h>

#define  LOG_TAG    "libgl2jni"
#define  LOGI(...)  __android_log_print(ANDROID_LOG_INFO,LOG_TAG,__VA_ARGS__)
#define  LOGE(...)  __android_log_print(ANDROID_LOG_ERROR,LOG_TAG,__VA_ARGS__)

#endif //OPENGLESFRAMEWORK_LOG_H
