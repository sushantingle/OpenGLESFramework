//
// Created by Sushant on 11-07-2021.
//

#ifndef OPENGLESFRAMEWORK_GAMEOBJECT_H
#define OPENGLESFRAMEWORK_GAMEOBJECT_H

namespace GLCore{
    class GameObject{
    public:
        GameObject(unsigned int id) : m_Id(id) {}
        virtual ~GameObject() = default;

        virtual void OnCreate() {}
        virtual void OnDestroy() {}
        virtual void OnUpdate() {}

        const unsigned int GetID() const {return m_Id;}
    protected:
        unsigned int m_Id;
    };
}

#endif //OPENGLESFRAMEWORK_GAMEOBJECT_H
