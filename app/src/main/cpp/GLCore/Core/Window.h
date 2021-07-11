//
// Created by Sushant on 10-07-2021.
//

#ifndef OPENGLESFRAMEWORK_WINDOW_H
#define OPENGLESFRAMEWORK_WINDOW_H
#include <memory>

namespace GLCore {

    class Scene;
    class Window {

    public:
        void OnCreate(unsigned int w, unsigned int h);
        void OnDestroy();
        void OnResize(unsigned int w, unsigned int h);

        void OnTouchDown(int index, unsigned int xPos, unsigned int yPos);
        void OnTouchUp(int index, unsigned int xPos, unsigned int yPos);
        void OnTouchMove(int index, unsigned int xPos, unsigned int yPos);

        void OnDraw();

        void RegisterScene(std::unique_ptr<Scene> scene) {m_Scene = std::move(scene);}
    private:
        unsigned int m_Width;
        unsigned int m_Height;

        std::unique_ptr<Scene> m_Scene;
    };
}

#endif //OPENGLESFRAMEWORK_WINDOW_H
