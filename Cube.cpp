// glm::vec3
#include "Cube.h"
#include <iostream>

Cube::Cube() : initialVertices {-1.0f, -1.0f,  1.0f,   //FRONT-LEFT-DOWN
                                -1.0f,  1.0f,  1.0f,   //FRONT-LEFT-UP
                                 1.0f,  1.0f,  1.0f,   //FRONT-RIGHT-UP
                                 1.0f, -1.0f,  1.0f,   //FRONT-RIGHT-DOWN
    
                                 1.0f,  1.0f, -1.0f,   //BACK-RIGHT-UP
                                 1.0f, -1.0f, -1.0f,   //BACK-RIGHT-DOWN
                                -1.0f, -1.0f, -1.0f,   //BACK-LEFT-DOWN
                                -1.0f,  1.0f, -1.0f}   //BACK-LEFT-UP
{
    for(int i=0; i<24; i++){
        vertices[i]=initialVertices[i];
    }
}


GLfloat Cube::getVertice(int index)
{
    return vertices[index];
}

void Cube::setVertice(int index, float value)
{
    vertices[index]=value;
    
}
void Cube::update(float &time){
    
    double x1=vertices[3];
    double x2=vertices[6];
    double v1=0;
    double v2=0;
    
    double m=2;
    int k=20;
    
    double h = 0.01; //newTime-time;
    
    double F1 = k*(x2-x1-10);
    double F2 = k*(x1-x2+10);
    
    v1 = v1 + F1*h/m;
    x1 = x1 + v1*h;
    v2 = v2 + F2*h/m;
    x2 = x2 + v2*h;
    
    vertices[3]=x1;
    vertices[6]=x2;

    //std::cout << F1 << std::endl;
    
}

void Cube::temp(){
    // m är massa
    int m = 2;
    
    // h är en steglängd
    // k är fjäderkonstant
    // d är dämpningskonstant
    double h = 0.01;
    int k = 20;
    
    
    // Number of samples
    int N = 100;
    
    double x1 = vertices[3];
    double x2 = vertices[6];
    double v1 = 0;
    double v2 = 0;
    
    double F1[100];
    double F2[100];
    
    for (int n=2; n<N; n++){

        F1[n] = k*(x2-x1-10);
        F2[n] = k*(x1-x2+10);

        v1 = v1 + F1[n]*h/m;
        x1 = x1 + v1*h;
        v2 = v2 + F2[n]*h/m;
        x2 = x2 + v2*h;
        
        vertices[3]=x1;
        vertices[6]=x2;
        
        
        std::cout << vertices[3] << std::endl;
    }
    
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



