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

double timeSinceStart; //Time variable
double mousePushPosX=0, mousePushPosY=0;
float up = 0, down = 0, left = 0, right = 0;
float transX=0, transY=0, transZ=0;

Cube cube1 = Cube();

/* - Function Declarations - */
void drawCube();
void display();
void init (void);
void keyboard(unsigned char key, int x, int y);
static void error_callback(int error, const char* description);
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
void rotCamera();


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
    
    
    
    
    /* ---- Cube ----- */


        
    /*
    //Initial values
    int m = 2;
    double h = 0.015;
    int k = 30;
    float d = 1.0f;
    
    
    glm::vec3 vert1 = cube1.massVec[3].getPosition();
    glm::vec3 vert2 = cube1.massVec[3].getPosition();

    
    
    double v1 = -1;
    double v2 = 1;
    
    double F1;
    double F2;
    */
    
    /*---------------------*/
    
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
        
        rotCamera();
        
        glPushMatrix();
        
        timeSinceStart = (float)glfwGetTime(); //update timevariable
        //cube1.update(timeSinceStart);
        
        /* ----------------------- Cube code ---------------------------- */
        
        /*
        F1 = k*(x2-x1-2)+d*(v2-v1);
        F2 = k*(x1-x2+2)+d*(v1-v2);
        
        
        v1 = v1 + F1*h/m;
        x1 = x1 + v1*h;
        v2 = v2 + F2*h/m;
        x2 = x2 + v2*h;
        
        cube1.setVertice(3, x2);
        cube1.setVertice(6, x2);
         */
        
            glTranslatef(-0.5f, 0, -0.5f);
            cube1.update();
            cube1.transBot(glm::vec3(transX,transY,transZ));
            cube1.draw();
        glPopMatrix();

        
        /* ------------------------------------------------------------- */
        
        glfwSwapBuffers(window);
        glfwPollEvents();
        
        
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
    float camStep=2.0f;
    float transStep=0.01f;
    
    switch (key) {
        case GLFW_KEY_ESCAPE:
            glfwSetWindowShouldClose(window, GL_TRUE);
            break;
        case GLFW_KEY_UP:
            up+=camStep;
            break;
        case GLFW_KEY_DOWN:
            down-=camStep;
            break;
        case GLFW_KEY_LEFT:
            left-=camStep;
            break;
        case GLFW_KEY_RIGHT:
            right+=camStep;
            break;
            
        case GLFW_KEY_BACKSPACE:
            right=0;
            left=0;
            up=0;
            down=0;
            break;
            
            
            
        /* Cube controls */
        case GLFW_KEY_W:
            transZ-=transStep;
            break;
            
        case GLFW_KEY_S:
            transZ+=transStep;
            break;
            
        case GLFW_KEY_A:
            transX-=transStep;
            break;
        
        case GLFW_KEY_D:
            transX+=transStep;
            
            break;
        
        case GLFW_KEY_SPACE:
            cube1.jump();
            break;
            
        default:
            break;
    }
    
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





void rotCamera(){
    
     
     if (up+down > 40){
     up = 40;
     down = 0;
     }
     else if (up+down < -40){
     up = -40;
     down = 0;
     }
    
    
    glTranslatef(0.0f, 0.0f, -3.0f);
    glRotatef(up+down, 1.0f, 0.0f, 0.0f);
    glRotatef(left+right, 0.0f, 1.0f, 0.0f);
}

