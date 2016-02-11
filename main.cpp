/*
Author: http://stackoverflow.com/questions/22636069/cube-rotation-opengl
*/


#include <GL/glew.h>

#if defined (__APPLE_CC__)
    #include <OpenGL/gl.h>
    #include <OpenGL/glu.h>
    #include <GLUT/glut.h>
#else
    #include <GL/gl.h>       /* assert OpenGL 3.2 core profile available. */
    #include <GL/glu.h>
    #include <GL/glut.h>
#endif

#include <glfw/glfw3.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>

/* -- Global Variables -- */
GLuint vbo_cube_vertices, vbo_cube_colors;
GLuint ibo_cube_elements;



float transZ=50;      
float rotateA=0;         

float rotateAspeed=0.0;

double timeSinceStart;



void cube (float dimX, float dimY, float dimZ)
  {
  
  glMatrixMode(GL_MODELVIEW);
  glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);

  glPushMatrix();
  glTranslatef(0,dimY/2,0);

  glScalef(dimX/4, dimY/4, dimZ/4);

  
  glBegin(GL_QUADS);     


  
  glColor3f(1.0f, 0.0f, 0.0f); 

    glVertex3f(1.0, 1.0, 1.0); // TOP-RIGHT-NEAR
    glVertex3f(-1.0, 1.0, 1.0); // TOP-LEFT-NEAR
    glVertex3f(-1.0, 1.0, -1.0); //TOP-LEFT-FAR
    glVertex3f(1.0, 1.0, -1.0); // TOP-RIGHT-FAR


    glVertex3f(1.0, -1.0, 1.0); //BOTTOM-RIGHT-NEAR
    glVertex3f(-1.0, -1.0, 1.0); //BOTTOM-LEFT-NEAR
    glVertex3f(-1.0, -1.0, -1.0); //BOTTOM-LEFT-FAR
    glVertex3f(1.0, -1.0, -1.0); //BOTTOM-RIGHT-FAR

    glVertex3f(1.0, 1.0, -1.0); //TOP-RIGHT-FAR
    glVertex3f(-1.0, 1.0, -1.0); //TOP-LEFT-FAR
    glVertex3f(-1.0, -1.0, -1.0); //BOTTOM-LEFT-FAR
    glVertex3f(1.0, -1.0, -1.0); //BOTTOM-RIGHT-FAR


    glVertex3f(1.0, 1.0, 1.0); //TOP-FRONT-NEAR
    glVertex3f(1.0, 1.0, -1.0); //TOP-BACK-FAR
    glVertex3f(1.0, -1.0, -1.0); //BOTTOM-BACK-FAR
    glVertex3f(1.0, -1.0, 1.0); //BOTTOM-FRONT-NEAR


    glVertex3f(-1.0, 1.0, 1.0); //TOP-FRONT-NEAR
    glVertex3f(-1.0, 1.0, -1.0); //TOP-BACK-FAR
    glVertex3f(-1.0, -1.0, -1.0);//BOTTOM-BACK-FAR
    glVertex3f(-1.0, -1.0, 1.0); //BOTTOM-FRONT-NEAR
    
    glVertex3f(1.0f,  1.0f,  1.0f);    // x, y
    glVertex3f(-1.0f, 1.0f, 1.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glVertex3f(1.0f, -1.0f,  1.0f);



  glEnd();
  

  glPopMatrix();

  

  /*
  glEnableClientState(GL_VERTEX_ARRAY);
 
  static GLfloat vertices[] = {0.25, 0.25, 1.00, 3.25, 1.75, 0.25, 1.75, 3.25, 2.50, 0.25, 3.25, 3.25};
  glVertexPointer(2, GL_FLOAT, 0, vertices);
 
  //Nummerierung der Punkte des Wuerfels
  static GLubyte frontIndices[] = {4, 5, 6, 7};
  static GLubyte rightIndices[] = {1, 2, 6, 5};
  static GLubyte bottomIndices[] = {0, 1, 5, 4};
  static GLubyte backIndices[] = {0, 3, 2, 1};
  static GLubyte leftIndices[] = {0, 4, 7, 3};
  static GLubyte topIndices[] = {2, 3, 7, 6};
 
  glDrawElements(GL_QUADS, 4, GL_UNSIGNED_BYTE, frontIndices);
  glDrawElements(GL_QUADS, 4, GL_UNSIGNED_BYTE, rightIndices);
  glDrawElements(GL_QUADS, 4, GL_UNSIGNED_BYTE, bottomIndices);
  glDrawElements(GL_QUADS, 4, GL_UNSIGNED_BYTE, backIndices);
  glDrawElements(GL_QUADS, 4, GL_UNSIGNED_BYTE, leftIndices);
  glDrawElements(GL_QUADS, 4, GL_UNSIGNED_BYTE, topIndices);
  glDisableClientState(GL_VERTEX_ARRAY);
  */

}


void updatePosition(){


}

void display()
{
  double rotSpeed = timeSinceStart/4;

  timeSinceStart = (double)glutGet(GLUT_ELAPSED_TIME)/1000;


  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );


  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  //gluLookAt(transZ*cos(rotateA),50,transZ*sin(rotateA), 0,10,0, 0,1,0);
  gluLookAt(transZ*cos(rotSpeed),50,transZ*sin(rotSpeed), 0,10,0, 0,1,0);
  
  cube(50,50,50);

  glFlush();            

  glutSwapBuffers();

}

void init (void)
{  
  glClearColor(0.8, 0.8, 0.8, 1.0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  glFrustum(-1, 1, -1, 1, 1, 1000);

  glEnable(GL_DEPTH_TEST); 
}


void keyboard(unsigned char key, int x, int y)
{
  switch (key) {
    case 27:                
    exit(0);
    break;
    case 'S':
    transZ+=1.0f;
    glutPostRedisplay();  
    break;
    case 'W':
    transZ-=1.0f;
    if (transZ<0) transZ=0;
    glutPostRedisplay();  
    break;
    case 's':
    transZ+=0.5f;
    glutPostRedisplay();  
    break;
    case 'w':
    transZ-=0.5f;
    if (transZ<0) transZ=0;
    glutPostRedisplay(); 
    break;
    case 'A':
    rotateAspeed+=0.001f;
    glutPostRedisplay();  
    break;
    case 'a':
    rotateAspeed+=0.001f;
    glutPostRedisplay();  
    break;
    case 'D':
    rotateAspeed-=0.001f;
    glutPostRedisplay();  
    break;
    case 'd':
    rotateAspeed-=0.001f;
    glutPostRedisplay();  
    break;

  }
}

void idle(void)
{
  rotateA=rotateA + rotateAspeed;
  glutPostRedisplay();    
}


int main(int argc, char** argv)
{  
 glutInit(&argc, argv);
 glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
 glutInitWindowSize (500, 500);
 glutInitWindowPosition (100, 100);
 glutCreateWindow ("Cube");
 init ();

 glutDisplayFunc(display);
 glutIdleFunc(idle); 

 glutKeyboardFunc(keyboard); 
 glutMainLoop();
 return 0;
}