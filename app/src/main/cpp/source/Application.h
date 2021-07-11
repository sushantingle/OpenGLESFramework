//
// Created by Sushant on 11-07-2021.
//

#ifndef OPENGLESFRAMEWORK_APPLICATION_H
#define OPENGLESFRAMEWORK_APPLICATION_H

#include "../GLCore/Core/Window.h"
#include "../GLCore/Core/Scene.h"
#include "../GLCore/GLCore.h"
#include "TestObject.h"

class Application {
public:
    Application() {

    }

    void Init(unsigned int width, unsigned int height) {
        std::unique_ptr<GLCore::Scene> scene = std::unique_ptr<GLCore::Scene>(new GLCore::Scene());
        scene->AddObject(new TestObject(0));
        m_Window.RegisterScene(std::move(scene));

        m_Window.OnCreate(width, height);
    }

    ~Application() {
        m_Window.OnDestroy();
    }

    void Draw() {
        m_Window.OnDraw();
    }

private:
    GLCore::Window m_Window;
};
#endif //OPENGLESFRAMEWORK_APPLICATION_H
