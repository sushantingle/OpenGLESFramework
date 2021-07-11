//
// Created by Sushant on 10-07-2021.
//

#ifndef OPENGLESFRAMEWORK_WINDOW_H
#define OPENGLESFRAMEWORK_WINDOW_H
namespace GLCore {
    class Window {

    public:
        void OnCreate(unsigned int w, unsigned int h);
        void OnDestroy();
        void OnResize(unsigned int w, unsigned int h);

        void OnTouchDown(int index, unsigned int xPos, unsigned int yPos);
        void OnTouchUp(int index, unsigned int xPos, unsigned int yPos);
        void OnTouchMove(int index, unsigned int xPos, unsigned int yPos);

        void OnDraw();
    private:
        unsigned int m_Width;
        unsigned int m_Height;
    };
}

#endif //OPENGLESFRAMEWORK_WINDOW_H
