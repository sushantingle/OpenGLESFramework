//
// Created by Sushant on 11-07-2021.
//

#include "Scene.h"
#include "../GLCore.h"

namespace GLCore{
    Scene::Scene() {

    }

    Scene::~Scene() {
        for(GameObject* obj : m_Container)
        {
            obj->OnDestroy();
            delete obj;
            obj = nullptr;
        }
        m_Container.clear();
    }

    void Scene::AddObject(GameObject *obj) {
        auto find = std::find_if(m_Container.begin(), m_Container.end(), [&](const GameObject* gameObject) -> bool {
            return obj->GetID() == gameObject->GetID();
        });

        assert(find == m_Container.end());

        m_Container.push_back(obj);
        obj->OnCreate();
    }

    void Scene::RemoveObject(unsigned int id) {
        auto it = std::find_if(m_Container.begin(), m_Container.end(), [&](const GameObject* gameObject) -> bool {
            return id == gameObject->GetID();
        });

        if (it != m_Container.end())
        {
            GLCore::GameObject* obj = static_cast<GLCore::GameObject*>(*it);
            obj->OnDestroy();
            delete * it;
            m_Container.erase(it);
        }
        else
        {
            LOGE("Couldn't find object with ID %d to delete.", id);
        }
    }

    void Scene::OnUpdate() {
        for(GameObject* obj : m_Container)
            obj->OnUpdate();
    }
}