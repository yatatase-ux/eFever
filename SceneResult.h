#pragma once
#include "SceneBase.h"

class SceneResult : public SceneBase
{
public:
    SceneResult();
    virtual ~SceneResult();

   

    void Input() override;
    void Update() override;
    void Draw() override;
};