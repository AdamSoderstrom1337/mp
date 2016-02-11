#ifndef CUBE_H_INCLUDED
#define CUBE_H_INCLUDED

#include <glfw/glfw3.h>
#include <GL/glut.h>
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

