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

    GLfloat vertices[24];

public:
    Cube();
    GLfloat* get();
    void set(int index, glm::vec3 values );
    void draw();

};


#endif // CUBE_H_INCLUDED

