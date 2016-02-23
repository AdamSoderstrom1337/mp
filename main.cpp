#include <GL/glew.h>
#include <glm/glm.hpp>

#if defined (__APPLE_CC__)
    #include <OpenGL/gl.h>
#else
    #include <GL/gl.h>
#endif

#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <stdio.h>

#include "Cube.h"




/* -- Global Variables -- */

float up = 0, down = 0, left = 0, right = 0;
float transX=0, transY=0, transZ=0;

Cube cube1 = Cube();

/* - Function Declarations - */

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
        
        rotCamera();

        
        /* ----------------------- Render code ---------------------------- */
    
        glPushMatrix();
            glTranslatef(-0.5f, 0, -0.5f);
            cube1.update();
            cube1.transBot(glm::vec3(transX,transY,transZ));
            cube1.draw();
        glPopMatrix();

        
        /* ----------------------------------------------------------------- */
        
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

