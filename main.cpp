#include <GL/glew.h>
#include <glm/glm.hpp>

#if defined (__APPLE_CC__)
    #include <OpenGL/gl.h>
    #include<OpenGL/glu.h>
#else
    #include <GL/gl.h>
    #include<GL/glu.h>
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
Cube cube2 = Cube();



/* - Function Declarations - */

void keyboard(unsigned char key, int x, int y);
static void error_callback(int error, const char* description);
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
void rotCamera();


int main(void)
{
    int option1, option2;

    std::cout << "[1] - Rubber" << std::endl
    << "[2] - Jelly"  << std::endl << std::endl;
    
    std::cout << "Enter material 1: ";
    std::cin >> option1;


    std::cout << "Enter material 2: ";
    std::cin >> option2;
    
    switch (option1) {
        case 1:
            cube1.setConstans(2000, 40); //Rubber
            break;
        case 2:
            cube1.setConstans(200, 40); //Jelly
            break;
        default:
            break;
    }
    
    switch (option2) {
        case 1:
            cube2.setConstans(2000, 40); //Rubber
            break;
        case 2:
            cube2.setConstans(200, 40); //Jelly
            break;
        default:
            break;
    }
    
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
    
    glClearColor(0.6, 0.9, 1.0, 1.0);
    glLoadIdentity();
    
    glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);


    glfwSwapInterval(1);
    glfwSetKeyCallback(window, key_callback);

    while (!glfwWindowShouldClose(window))
    {
        float ratio;
        int width, height;
        unsigned int GridSizeX = 16;
        unsigned int GridSizeY = 16;
        unsigned int SizeX = 1;
        unsigned int SizeY = 1;

        glfwGetFramebufferSize(window, &width, &height);
        ratio = width / (float) height;

        glViewport(0, 0, width, height);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        
        glEnable(GL_CULL_FACE);
        glEnable(GL_NORMALIZE);
        glEnable(GL_DEPTH_TEST);
        glCullFace(GL_FRONT);

        glFrustum(-ratio, ratio, -1.0f, 1.0f, 1, 50);

        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        
        glCullFace(GL_FRONT);
        glLoadIdentity();
         
        
        gluLookAt(0.0f, 0.5f, 3.0f,
                  cube1.getCenter().x-0.5f, 0.0f, cube1.getCenter().z,
                  0.0f, 1.0f, 0.0f);
        


        
        /* ----------------------- Render code ---------------------------- */
    
        //Floor
        glPushMatrix();
        glRotatef(90, 1.0f, 0.0f, 0.0f);
        glTranslatef(-8.0f, -8.0f, 1.0f);
            glBegin(GL_QUADS);
            for (unsigned int x =0;x<GridSizeX;++x)
                for (unsigned int y =0;y<GridSizeY;++y)
                {
                    if ((x+y)%2) //modulo 2
                        glColor3f(1.0f,1.0f,1.0f); //white
                    else
                        glColor3f(0.0f,0.0f,0.0f); //black
                    
                    glVertex2f(    x*SizeX,    y*SizeY);
                    glVertex2f((x+1)*SizeX,    y*SizeY);
                    glVertex2f((x+1)*SizeX,(y+1)*SizeY);
                    glVertex2f(    x*SizeX,(y+1)*SizeY);
                    
                }
            glEnd();
        glPopMatrix();
        
        glColor3f(0.5f, 0.5f, 0.5f);
        glPushMatrix();
            glTranslatef(-1.4f, 0, -0.5f);
            cube1.draw();
            cube1.transBot(glm::vec3(transX,transY,transZ));
            cube1.update();
        glPopMatrix();
        
        glColor3f(1.0f, 0.5f, 0.25f);
            glPushMatrix();
            glTranslatef(0.4f, 0, -0.5f);
            cube2.update();
            cube2.transBot(glm::vec3(transX,transY,transZ));
            cube2.draw();
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
        
        case GLFW_KEY_R:
            cube1.jump();
            break;
            
        case GLFW_KEY_F:
            cube2.jump();
            break;

        default:
            break;
    }

}

void rotCamera(){

    /*
     if (up+down > 40){
     up = 40;
     down = 0;
     }
     else if (up+down < 0){
     up = 0;
     down = 0;
     }


    glTranslatef(0.0f, 0.0f, -3.0f);
    glRotatef(up+down, 1.0f, 0.0f, 0.0f);
    glRotatef(left+right, 0.0f, 1.0f, 0.0f);
     */
    
    glTranslatef(0.0f, 0.0f, -3.0f);
    glRotatef(glfwGetTime()*10, 0.0f, 1.0f, 0.0f);
    
    
}








