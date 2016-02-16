#ifndef CUBE_H_INCLUDED
#define CUBE_H_INCLUDED

#if defined (__APPLE_CC__)
    #include <GLUT/glut.h>
#else
    #include <GL/glut.h>
#endif

#include <GLFW/glfw3.h>
#include <glm/glm.hpp>


class Cube
{
private:

    
    GLfloat initialVertices[24];
    

public:
    Cube();
    GLfloat vertices[24];
    GLfloat getVertice(int index);
    void setVertice(int index, float value);
    void draw();
    void update(float &time);
    void temp();


};


#endif // CUBE_H_INCLUDED

