//
// Created by Sushant on 11-07-2021.
//

#include "TestObject.h"
#include "../GLCore/GLCore.h"
#include "../GLCore/Utils/AssetManager.h"


void TestObject::OnCreate() {
    std::string vs = GLCore::Utils::AssetManager::GetInstance().ReadFile("shaders/test.vert");
    std::string fs = GLCore::Utils::AssetManager::GetInstance().ReadFile("shaders/test.frag");

    m_Shader = GLCore::Utils::Shader::FromGLSLTextFiles(vs, fs);
    if (m_Shader == nullptr)
    {
        LOGE("Could not create Shader");
    }
}

void TestObject::OnDestroy() {
    if (m_Shader)
    {
        delete m_Shader;
        m_Shader = nullptr;
    }
}

void TestObject::OnUpdate() {
    const GLfloat gTriangleVertices[] = { 0.0f, 0.5f, -0.5f, -0.5f,
                                          0.5f, -0.5f };

    static float grey;
    grey += 0.01f;
    if (grey > 1.0f) {
        grey = 0.0f;
    }
    glClearColor(grey, grey, grey, 1.0f);
    checkGlError("glClearColor");
    glClear( GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
    checkGlError("glClear");

    GLuint gvPositionHandle = glGetAttribLocation(m_Shader->GetRendererID(), "vPosition");
    checkGlError("glGetAttribLocation");
    LOGI("glGetAttribLocation(\"vPosition\") = %d\n",
         gvPositionHandle);

    glUseProgram(m_Shader->GetRendererID());
    checkGlError("glUseProgram");

    glVertexAttribPointer(gvPositionHandle, 2, GL_FLOAT, GL_FALSE, 0, gTriangleVertices);
    checkGlError("glVertexAttribPointer");
    glEnableVertexAttribArray(gvPositionHandle);
    checkGlError("glEnableVertexAttribArray");
    glDrawArrays(GL_TRIANGLES, 0, 3);
    checkGlError("glDrawArrays");
}