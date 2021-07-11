//
// Created by Sushant on 11-07-2021.
//

#ifndef OPENGLESFRAMEWORK_SCENE_H
#define OPENGLESFRAMEWORK_SCENE_H

#include "../GLCore.h"
#include "GameObject.h"

namespace GLCore{
    class Scene{
    public:
        Scene();
        virtual ~Scene();

        void AddObject(GameObject* obj);
        void RemoveObject(unsigned int id);

        void OnUpdate();

    private:
        std::vector<GameObject*> m_Container;
    };
}
#endif //OPENGLESFRAMEWORK_SCENE_H
