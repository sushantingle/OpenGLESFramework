//
// Created by Sushant on 10-07-2021.
//

#include "Window.h"
#include "Scene.h"

namespace GLCore{
    void Window::OnCreate(unsigned int w, unsigned int h) {
        m_Width = w;
        m_Height = h;
    }

    void Window::OnDestroy() {

    }

    void Window::OnResize(unsigned int w, unsigned int h) {
        m_Width = w;
        m_Height = h;
    }

    void Window::OnTouchDown(int index, unsigned int xPos, unsigned int yPos) {

    }

    void Window::OnTouchUp(int index, unsigned int xPos, unsigned int yPos) {

    }

    void Window::OnTouchMove(int index, unsigned int xPos, unsigned int yPos) {

    }

    void Window::OnDraw() {
        if (m_Scene)
            m_Scene->OnUpdate();
    }
}

