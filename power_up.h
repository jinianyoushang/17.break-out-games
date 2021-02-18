/*******************************************************************
** This code is part of Breakout.
**
** Breakout is free software: you can redistribute it and/or modify
** it under the terms of the CC BY 4.0 license as published by
** Creative Commons, either version 4 of the License, or (at your
** option) any later version.
******************************************************************/
#ifndef POWER_UP_H
#define POWER_UP_H
#include <string>

#include <glad/glad.h>
#include <glm/glm.hpp>

#include "game_object.h"


// The size of a PowerUp block
const glm::vec2 POWERUP_SIZE(60.0f, 20.0f);
// Velocity a PowerUp block has when spawned
const glm::vec2 VELOCITY(0.0f, 150.0f);


// PowerUp inherits its state and rendering functions from
// GameObject but also holds extra information to state its
// active duration and whether it is activated or not. 
// The type of PowerUp is stored as a string.
class PowerUp : public GameObject 
{
public:
    /*Speed: ����С��20%���ٶ�
    Sticky: ��С������ҵ���Ӵ�ʱ��С��ᱣ��ճ�ڵ����ϵ�״ֱ̬���ٴΰ��¿ո�����������������ͷ�С��ǰ�ҵ������ʵ�λ��
    Pass-Through: ��ʵ��ש�����ײ�������ã�ʹС����Դ������ݻٶ��ש��
    Pad-Size-Increase: ������ҵ���50���صĿ��
    Confuse: ��ʱ���ڼ���confuse������Ч���Ի����
    Chaos: ��ʱ���ڼ���chaos������Ч��ʹ�����ʧ����*/

    // powerup state
    std::string Type;
    float       Duration;	
    bool        Activated;

    // constructor
    PowerUp(std::string type, glm::vec3 color, float duration, glm::vec2 position, Texture2D texture) 
        : GameObject(position, POWERUP_SIZE, texture, color, VELOCITY), Type(type), Duration(duration), Activated() { }
};

#endif