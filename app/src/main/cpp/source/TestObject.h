//
// Created by Sushant on 11-07-2021.
//

#ifndef OPENGLESFRAMEWORK_TESTOBJECT_H
#define OPENGLESFRAMEWORK_TESTOBJECT_H
#include "../GLCore/Core/GameObject.h"
#include "../GLCore/Utils/Shader.h"

class TestObject : public GLCore::GameObject {
public:
    TestObject(unsigned  int id):GLCore::GameObject(id){}
    ~TestObject() {}

    void OnCreate() override;
    void OnDestroy() override;
    void OnUpdate() override;

private:
    GLCore::Utils::Shader* m_Shader;

};

#endif //OPENGLESFRAMEWORK_TESTOBJECT_H
