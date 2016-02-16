#include <GL/glew.h>
#include <glm/glm.hpp>

#if defined (__APPLE_CC__)
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#else
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#endif

#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <stdio.h>

#include "Cube.h"




/* -- Global Variables -- */
float transZ=0;
float rotateA=0;
double timeSinceStart; //Time variable


/* - Function Declarations - */
void drawCube();
void display();
void init (void);
void keyboard(unsigned char key, int x, int y);
static void error_callback(int error, const char* description);
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);



int main(void)
{
    
    GLFWwindow* window;
    glfwSetErrorCallback(error_callback);
    
    if (!glfwInit())
        exit(EXIT_FAILURE);
    
    window = glfwCreateWindow(640, 480, "Simple example", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    
    glfwMakeContextCurrent(window);
    init();
    
    glfwSwapInterval(1);
    glfwSetKeyCallback(window, key_callback);
    
    
    Cube cube1 = Cube();
    
    while (!glfwWindowShouldClose(window))
    {
        
        float ratio;
        int width, height;
        
        glfwGetFramebufferSize(window, &width, &height);
        ratio = width / (float) height;
        
        glViewport(0, 0, width, height);
        glClear(GL_COLOR_BUFFER_BIT);
        
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        
        glFrustum(-ratio, ratio, -1.0f, 1.0f, 1, 50);
        
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        
        /* ----------------------- camera controls ---------------------- */
        double mouseX, mouseY;
        
        glfwGetCursorPos(window, &mouseX, &mouseY);
        gluLookAt(-mouseX/100, mouseY/100, 3, 0, 0, 0, 0.0, 1.0, 0.0);
        /* -------------------------------------------------------------- */
        
        
        /* ----------------------- Rendering code ---------------------- */
        
        glPushMatrix();
        cube1.draw();
        
        cube1.update(timeSinceStart);
        
        
        glPopMatrix();
        
        /* ------------------------------------------------------------- */
        
        glfwSwapBuffers(window);
        glfwPollEvents();
        
        timeSinceStart = (float)glfwGetTime(); //update timevariable
    }
    
    
    glfwDestroyWindow(window);
    glfwTerminate();
    exit(EXIT_SUCCESS);
}

static void error_callback(int error, const char* description)
{
    fputs(description, stderr);
}
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
}

void init (void)
{
    glClearColor(0.8, 0.8, 0.8, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    
    glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
    
}

void drawCube ()
{
    
    glEnableClientState(GL_VERTEX_ARRAY);
    glColor3f(1.0f, 0.0f, 0.0f);
    
    GLfloat vertices[] = {-1.0f, -1.0f,  1.0f,  //FRONT-LEFT-DOWN
        -1.0f,  1.0f,  1.0f,  //FRONT-LEFT-UP
        1.0f,  1.0f,  1.0f,  //FRONT-RIGHT-UP
        1.0f, -1.0f,  1.0f,  //FRONT-RIGHT-DOWN
        1.0f,  1.0f, -1.0f,  //BACK-RIGHT-UP
        1.0f, -1.0f, -1.0f,  //BACK-RIGHT-DOWN
        -1.0f, -1.0f, -1.0f,  //BACK-LEFT-DOWN
        -1.0f,  1.0f, -1.0f}; //BACK-LEFT-UP
    
    glVertexPointer(3, GL_FLOAT, 0, vertices);
    
    //Declare vertex indices
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



void keyboard(unsigned char key, int x, int y)
{
    switch (key) {
        case 27:
            exit(0);
            break;
        case 'S':
            transZ+=2.0f;
            break;
        case 'W':
            transZ-=2.0f;
            break;
        case 's':
            transZ+=2.0f;
            break;
        case 'w':
            transZ-=2.0f;
            break;
            
    }
}




/*
 void display()
 {
 // - Update timevariable -
 
 timeSinceStart = (float)glfwGetTime();
 double rotSpeed = timeSinceStart*45;
 
 
 glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
 
 
 glMatrixMode(GL_MODELVIEW);
 glLoadIdentity();
 
 gluLookAt(0,25+transZ,50, 0,0,0, 0,1,0); // (eye, center, up)
 
 
 glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
 glMatrixMode(GL_MODELVIEW);
 
 
 glPushMatrix();
 
 glRotatef(rotSpeed, 0.0f, 1.0f, 0.0f);
 glScalef(10.0f,10.0f,10.0f);
 drawCube();
 
 glPopMatrix();
 
 glFlush();
 glutSwapBuffers();
 
 }
 */
