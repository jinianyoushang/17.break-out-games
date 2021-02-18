#pragma once
/*******************************************************************
** This code is part of Breakout.
**
** Breakout is free software: you can redistribute it and/or modify
** it under the terms of the CC BY 4.0 license as published by
** Creative Commons, either version 4 of the License, or (at your
** option) any later version.
******************************************************************/
#ifndef GAME_H
#define GAME_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <vector>
#include <tuple>

#include "game_level.h"
#include "power_up.h"


// ��������Ϸ�ĵ�ǰ״̬
enum GameState {
    GAME_ACTIVE,
    GAME_MENU,
    GAME_WIN
};

// ��ײ�ķ���
enum Direction {
    UP,
    RIGHT,
    DOWN,
    LEFT
};

// Defines a Collision typedef that represents collision data
typedef std::tuple<GLboolean, Direction, glm::vec2> Collision; // <collision?, what direction?, difference vector center - closest point>
// ��ʼ������Ĵ�С
const glm::vec2 PLAYER_SIZE(100, 20);
// ��ʼ�����������
const GLfloat PLAYER_VELOCITY(500.0f);
// ��ʼ������ٶ�
const glm::vec2 INITIAL_BALL_VELOCITY(100.0f, -350.0f);
// ��İ뾶
const GLfloat BALL_RADIUS = 12.5f;


// Game holds all game-related state and functionality.
// Combines all game-related data into a single class for
// easy access to each of the components and manageability.
class Game
{
public:
    // ��Ϸ״̬
    std::vector<GameLevel> Levels;
    GLuint                 Level;
    std::vector<PowerUp>  PowerUps;
    GameState  State;
    GLboolean  Keys[1024];
    GLuint     Width, Height;
    // �������ֵ
    GLuint Lives = 3;
    // ������
    GLboolean KeysProcessed[1024];
    // ���캯��/��������
    Game(GLuint width, GLuint height);
    ~Game();
    // ��ʼ����Ϸ״̬���������е���ɫ��/����/�ؿ���
    void Init();
    // ��Ϸѭ��
    void ProcessInput(GLfloat dt);
    void Update(GLfloat dt);
    void Render();
    void DoCollisions();
    //SpawnPowerUps�ڸ�����ש��λ������һ������
    void SpawnPowerUps(GameObject& block);
    //UpdatePowerUps�������е�ǰ������ĵ��ߡ�
    void UpdatePowerUps(GLfloat dt);
    // Reset
    void ResetLevel();
    void ResetPlayer();

};

#endif
