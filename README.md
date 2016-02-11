# mp

Skapade new branch, testar

void cube ()
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
