#ifndef CUBE_H_INCLUDED
#define CUBE_H_INCLUDED

#if defined (__APPLE_CC__)
    #include <GLUT/glut.h>
#else
    #include <GL/glut.h>
#endif

#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <vector>
#include "Mass.h"


class Cube
{
private:

    
    GLfloat initialVertices[24];
    
    //Spring values
    float m = 2.0f;
    float h = 0.015f;
    float k = 130.0f;
    float d = 20.0f;
    
    glm::vec3 g=glm::vec3(0.0f, 9.82f, 0.0f);
    
    glm::vec3 sXlenght = glm::vec3(1.0f, 0.0f,0.0f);
    glm::vec3 sYlenght = glm::vec3(0.0f, 1.0f,0.0f);
    glm::vec3 sZlenght = glm::vec3(0.0f, 0.0f,1.0f);
    glm::vec3 sXYZlenght = glm::vec3(1.0f, 1.0f,1.0f);


public:
    std::vector<Mass> massVec;
    Cube();
    Mass getMass(int index);
    
    std::vector<GLfloat> vertices;
    void draw();
    void update();
    void temp();
    void transBot(glm::vec3 _val);
    void jump();


};


#endif // CUBE_H_INCLUDED

