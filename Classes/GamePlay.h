#pragma once
#include "Header.h"

class GamePlay : public Layer
{
public:
    static Scene* createScene();
    
    CREATE_FUNC(GamePlay);
    
private:
    bool init() override;
    void update(float dt) override;
};
