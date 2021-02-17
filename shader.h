/*******************************************************************
** This code is part of Breakout.
**
** Breakout is free software: you can redistribute it and/or modify
** it under the terms of the CC BY 4.0 license as published by
** Creative Commons, either version 4 of the License, or (at your
** option) any later version.
******************************************************************/
#ifndef SHADER_H
#define SHADER_H

#include <string>

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>


// General purpsoe shader object. Compiles from file, generates
// compile/link-time error messages and hosts several utility 
// functions for easy management.
class Shader
{
public:
    // 状态
    GLuint ID;
    // 构造器
    Shader() { }
    // 把当前shader激活
    Shader& Use();
    //从给定的源代码编译着色器
    void    Compile(const GLchar* vertexSource, const GLchar* fragmentSource, const GLchar* geometrySource = nullptr); // Note: geometry source code is optional 
    // Utility functions
    // 工具函数
    void    SetFloat(const GLchar* name, GLfloat value, GLboolean useShader = false);
    void    SetInteger(const GLchar* name, GLint value, GLboolean useShader = false);
    void    SetVector2f(const GLchar* name, GLfloat x, GLfloat y, GLboolean useShader = false);
    void    SetVector2f(const GLchar* name, const glm::vec2& value, GLboolean useShader = false);
    void    SetVector3f(const GLchar* name, GLfloat x, GLfloat y, GLfloat z, GLboolean useShader = false);
    void    SetVector3f(const GLchar* name, const glm::vec3& value, GLboolean useShader = false);
    void    SetVector4f(const GLchar* name, GLfloat x, GLfloat y, GLfloat z, GLfloat w, GLboolean useShader = false);
    void    SetVector4f(const GLchar* name, const glm::vec4& value, GLboolean useShader = false);
    void    SetMatrix4(const GLchar* name, const glm::mat4& matrix, GLboolean useShader = false);
private:
    // Checks if compilation or linking failed and if so, print the error logs
    // 检查编译或者链接是否错误，如果错误打印错误日志
    void    checkCompileErrors(GLuint object, std::string type);
};

#endif