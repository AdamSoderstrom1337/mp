#ifndef CUBE_H_INCLUDED
#define CUBE_H_INCLUDED


#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <vector>
#include "Mass.h"


class Cube
{
private:

    //Spring values
    float m = 2.0f;
    float h = 0.015f;
    float k = 600.0f;
    float d = 20.0f;
    
    glm::vec3 g=glm::vec3(0.0f, 9.82f, 0.0f);
    glm::vec3 sXlenght = glm::vec3(1.0f, 0.0f,0.0f);
    glm::vec3 sYlenght = glm::vec3(0.0f, 1.0f,0.0f);
    glm::vec3 sZlenght = glm::vec3(0.0f, 0.0f,1.0f);
    glm::vec3 sXYZlenght = glm::vec3(1.0f, 1.0f,1.0f);


public:
    Cube();
    std::vector<Mass> massVec;
    void draw();
    void update();
    void transBot(glm::vec3 _val);
    void jump();


};


#endif // CUBE_H_INCLUDED

