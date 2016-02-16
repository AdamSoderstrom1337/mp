// glm::vec3
#include "Cube.h"
#include <iostream>

Cube::Cube() : initialVertices {-1.0f, -1.0f,  1.0f,   //Vertex 1
    -1.0f,  1.0f,  1.0f,
    1.0f,  1.0f,  1.0f,
    1.0f, -1.0f,  1.0f,
    1.0f,  1.0f, -1.0f,
    1.0f, -1.0f, -1.0f,
    -1.0f, -1.0f, -1.0f,
    -1.0f,  1.0f, -1.0f}
{
    for(int i=0; i<24; i++){
        vertices[i]=initialVertices[i];
    }
}

GLfloat* Cube::getVertices()
{
    return vertices;
}

void Cube::setVertices(int indexRow, glm::vec3 values )
{
    indexRow = (indexRow-1)*3 ;
    
    for (int i = 0; i < 3;i++){
        vertices[indexRow+i] = values[i];
    }
    
}

void Cube::update(double &time){
    //-1 1 1 TOP LEFT
    // 1 1 1 TOP RIGHT
    
    double newTime=glfwGetTime();
    
    double v1=0;
    double v2=0;
    double m=2;
    int k=20;
    
    double deltaTime = 0.01; //newTime-time;
    
    
    
    double F1 = k*(vertices[6] - vertices[3]-10);
    double F2 = k*(vertices[3] - vertices[6]+10);
    
    v1 = v1+F1*deltaTime/m;
    v2 = v2+F2*deltaTime/m;
    
    vertices[3]=vertices[3]+v1*deltaTime;
    vertices[6]=vertices[6]+v2*deltaTime;

    std::cout << F1 << std::endl;

    
}



void Cube::draw()
{
    glEnableClientState(GL_VERTEX_ARRAY);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertexPointer(3, GL_FLOAT, 0, vertices);
    
    GLubyte frontIndices[] = {0, 1, 2, 3};
    GLubyte rightIndices[] = {3, 2, 4, 5};
    GLubyte bottomIndices[] = {0, 3, 5, 6};
    GLubyte backIndices[] = {6, 5, 4, 7};
    GLubyte leftIndices[] = {0, 6, 7, 1};
    GLubyte topIndices[] = {1, 2, 4, 7};
    
    glDrawElements(GL_QUADS, 4, GL_UNSIGNED_BYTE, frontIndices);
    glDrawElements(GL_QUADS, 4, GL_UNSIGNED_BYTE, rightIndices);
    glDrawElements(GL_QUADS, 4, GL_UNSIGNED_BYTE, bottomIndices);
    glDrawElements(GL_QUADS, 4, GL_UNSIGNED_BYTE, backIndices);
    glDrawElements(GL_QUADS, 4, GL_UNSIGNED_BYTE, leftIndices);
    glDrawElements(GL_QUADS, 4, GL_UNSIGNED_BYTE, topIndices);
}



