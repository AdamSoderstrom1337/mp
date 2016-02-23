// glm::vec3
#include "Cube.h"
#include <iostream>


Cube::Cube(){
    
    /* Bottom */
    massVec.push_back(Mass::Mass(glm::vec3(0,0,0), glm::vec3(-1,-1,-1))); // BACK-BOT-LEFT
    massVec.push_back(Mass::Mass(glm::vec3(1,0,0), glm::vec3(1,-1,-1))); //BACK-BOT-RIGHT
    massVec.push_back(Mass::Mass(glm::vec3(1,0,1), glm::vec3(1,-1,1))); //FRONT-BOT-RIGHT
    massVec.push_back(Mass::Mass(glm::vec3(0,0,1), glm::vec3(-1,-1,1))); //FRONT-BOT-LEFT
    
    /* top */
    massVec.push_back(Mass::Mass(glm::vec3(0,1,0), glm::vec3(-1,1,-1))); // BACK-TOP-LEFT
    massVec.push_back(Mass::Mass(glm::vec3(1,1,0), glm::vec3(1,1,-1))); //BACK-TOP-RIGHT
    massVec.push_back(Mass::Mass(glm::vec3(1,1,1), glm::vec3(1,1,1))); //FRONT-TOP-RIGHT
    massVec.push_back(Mass::Mass(glm::vec3(0,1,1), glm::vec3(-1,1,1))); //FRONT-TOP-LEFT
    

    /* -- Add connections -- */
    
    massVec[0].addConnection(1);
    massVec[1].addConnection(0);
   
    massVec[2].addConnection(0);
    massVec[0].addConnection(2);
    
    massVec[3].addConnection(2);
    massVec[2].addConnection(3);
    
    massVec[3].addConnection(1);
    massVec[1].addConnection(3);
    
    massVec[3].addConnection(0);
    massVec[0].addConnection(3);
    
    /*-----------------------*/
    
}

void Cube::transBot(glm::vec3 _val){
    
    massVec[0].setPosition(massVec[0].getPosition()+_val);
    massVec[1].setPosition(massVec[1].getPosition()+_val);
    massVec[2].setPosition(massVec[2].getPosition()+_val);
    massVec[3].setPosition(massVec[3].getPosition()+_val);

    
}



void Cube::update(){
    
    Mass mass0=massVec[0];
    Mass mass1=massVec[1];
    Mass mass2=massVec[2];
    Mass mass3=massVec[3];
    Mass mass4=massVec[4];
    Mass mass5=massVec[5];
    Mass mass6=massVec[6];
    Mass mass7=massVec[7];
    
    glm::vec3 mass0Pos = mass0.getPosition();
    glm::vec3 mass1Pos = mass1.getPosition();
    glm::vec3 mass2Pos = mass2.getPosition();
    glm::vec3 mass3Pos = mass3.getPosition();
    glm::vec3 mass4Pos = mass4.getPosition();
    glm::vec3 mass5Pos = mass5.getPosition();
    glm::vec3 mass6Pos = mass6.getPosition();
    glm::vec3 mass7Pos = mass7.getPosition();
    
    
    glm::vec3 v0 = mass0.getVelocity();
    glm::vec3 v1 = mass1.getVelocity();
    glm::vec3 v2 = mass2.getVelocity();
    glm::vec3 v3 = mass3.getVelocity();
    glm::vec3 v4 = mass4.getVelocity();
    glm::vec3 v5 = mass5.getVelocity();
    glm::vec3 v6 = mass6.getVelocity();
    glm::vec3 v7 = mass7.getVelocity();
    
    glm::vec3 F0;
    glm::vec3 F1;
    glm::vec3 F2;
    glm::vec3 F3;
    glm::vec3 F4;
    glm::vec3 F5;
    glm::vec3 F6;
    glm::vec3 F7;
    
    
    /* Top */
    F4 =k*(mass5Pos-mass4Pos-sXlenght)+d*(v5-v4);        //x-led
    F4+=k*(mass0Pos-mass4Pos+sYlenght)+d*(v0-v4)-m*g;    //y-led
    F4+=k*(mass7Pos-mass4Pos-sZlenght)+d*(v7-v4);        //z-led
    
    F5 =k*(mass4Pos-mass5Pos+sXlenght)+d*(v4-v5);        //x-led
    F5+=k*(mass1Pos-mass5Pos+sYlenght)+d*(v1-v5)-m*g;    //y-led
    F5+=k*(mass6Pos-mass5Pos-sZlenght)+d*(v6-v5);        //z-led
    
    F6 =k*(mass7Pos-mass6Pos+sXlenght)+d*(v7-v6);        //x-led
    F6+=k*(mass2Pos-mass6Pos+sYlenght)+d*(v2-v6)-m*g;    //y-led
    F6+=k*(mass5Pos-mass6Pos+sZlenght)+d*(v5-v6);        //z-led

    
    F7 =k*(mass6Pos-mass7Pos-sXlenght)+d*(v6-v7);        //x-led
    F7+=k*(mass3Pos-mass7Pos+sYlenght)+d*(v3-v7)-m*g;    //y-led
    F7+=k*(mass4Pos-mass7Pos+sZlenght)+d*(v4-v7);        //z-led
    
    /* Bottom */
    
    
    
    F0 =k*(mass1Pos-mass0Pos-sXlenght)+d*(v1-v0);        //x-led
    F0+=k*(mass4Pos-mass0Pos-sYlenght)+d*(v4-v0)-m*g;    //y-led
    if(mass0.getPosition().y<=-1){
        F0+=8*m*g;
        mass0.setPosition(glm::vec3(mass0.getPosition().x, -1, mass0.getPosition().z));

    }
    F0+=k*(mass3Pos-mass0Pos-sZlenght)+d*(v3-v0);        //z-led
    
    
    
    F1 =k*(mass0Pos-mass1Pos+sXlenght)+d*(v0-v1);        //x-led
    F1+=k*(mass5Pos-mass1Pos-sYlenght)+d*(v5-v1)-m*g;    //y-led
    if(mass1.getPosition().y<=-1){
        F1+=8*m*g;
        mass1.setPosition(glm::vec3(mass1.getPosition().x, -1, mass1.getPosition().z));
    }
    F1+=k*(mass2Pos-mass1Pos-sZlenght)+d*(v2-v1);        //z-led
    
    
    
    F2 =k*(mass3Pos-mass2Pos+sXlenght)+d*(v3-v2);        //x-led
    F2+=k*(mass6Pos-mass2Pos-sYlenght)+d*(v6-v2)-m*g;    //y-led
    if(mass2.getPosition().y<=-1){
        F2+=8*m*g;
        mass2.setPosition(glm::vec3(mass2.getPosition().x, -1, mass2.getPosition().z));
    }
    
    F2+=k*(mass1Pos-mass2Pos+sZlenght)+d*(v1-v2);        //z-led
    
    
    
    F3 =k*(mass2Pos-mass3Pos-sXlenght)+d*(v2-v3);        //x-led
    F3+=k*(mass7Pos-mass3Pos-sYlenght)+d*(v7-v3)-m*g;    //y-led
    if(mass3.getPosition().y<=-1){
        F3+=8*m*g;
        mass3.setPosition(glm::vec3(mass3.getPosition().x, -1, mass3.getPosition().z));
    }
    F3+=k*(mass0Pos-mass3Pos+sZlenght)+d*(v0-v3);        //z-led

    
    
    mass0.setVelocity(mass0.getVelocity()+F0*h/m);
    mass0.setPosition(mass0.getPosition()+mass0.getVelocity()*h);
    
    mass1.setVelocity(mass1.getVelocity()+F1*h/m);
    mass1.setPosition(mass1.getPosition()+mass1.getVelocity()*h);
    
    mass2.setVelocity(mass2.getVelocity()+F2*h/m);
    mass2.setPosition(mass2.getPosition()+mass2.getVelocity()*h);
    
    mass3.setVelocity(mass3.getVelocity()+F3*h/m);
    mass3.setPosition(mass3.getPosition()+mass3.getVelocity()*h);
    
    mass4.setVelocity(mass4.getVelocity()+F4*h/m);
    mass4.setPosition(mass4.getPosition()+mass4.getVelocity()*h);
    
    mass5.setVelocity(mass5.getVelocity()+F5*h/m);
    mass5.setPosition(mass5.getPosition()+mass5.getVelocity()*h);
    
    mass6.setVelocity(mass6.getVelocity()+F6*h/m);
    mass6.setPosition(mass6.getPosition()+mass6.getVelocity()*h);
    
    mass7.setVelocity(mass7.getVelocity()+F7*h/m);
    mass7.setPosition(mass7.getPosition()+mass7.getVelocity()*h);
    
    
    massVec[0] = mass0;
    massVec[1] = mass1;
    massVec[2] = mass2;
    massVec[3] = mass3;
    massVec[4] = mass4;
    massVec[5] = mass5;
    massVec[6] = mass6;
    massVec[7] = mass7;


    
    /*
     
     4----------5
     |\         |\
     | \        | \
     |  7----------6
     |  |       |  |
     0--|-------1  |
      \ |        \ |
       \|         \|
        3----------2
     
     */
    
}


void Cube::jump(){
    for (int i=0; i<massVec.size(); i++) {
        massVec[i].setVelocity(massVec[i].getVelocity()+glm::vec3(0.0f,3.0f,0.0f));
    }
}


void Cube::draw()
{
    //array[1] = massvec[1].x
    //array[2] =massvec[1].y
    
    int arrSize = massVec.size()*3;
    float vBuffer[arrSize];
    
    
    
    for(int i=0; i<massVec.size(); i++){
        float x = massVec[i].getPosition().x;
        float y = massVec[i].getPosition().y;
        float z = massVec[i].getPosition().z;
        
        vBuffer[(i*3)] = x;
        vBuffer[(i*3)+1] = y;
        vBuffer[(i*3)+2] = z;
        
    }
    
    glEnableClientState(GL_VERTEX_ARRAY);
    
    glVertexPointer(3, GL_FLOAT, 0, vBuffer);
    
    GLubyte bottom[] = {3, 2, 1, 0};
    GLubyte top[] = {4, 5, 6, 7};
    GLubyte front[] = {7,6,2,3};
    GLubyte back[] = {1,5,4,0};
    GLubyte right[] = {2,6,5,1};
    GLubyte left[] = {4,7,3,0};
    
    /*
     
     4----------5
     |\         |\
     | \        | \
     |  7----------6
     |  |       |  |
     0--|-------1  |
      \ |        \ |
       \|         \|
        3----------2
     
     */

    


    glDrawElements(GL_QUADS, 4, GL_UNSIGNED_BYTE, bottom);
    glDrawElements(GL_QUADS, 4, GL_UNSIGNED_BYTE, top);
    glDrawElements(GL_QUADS, 4, GL_UNSIGNED_BYTE, front);
    glDrawElements(GL_QUADS, 4, GL_UNSIGNED_BYTE, right);
    glDrawElements(GL_QUADS, 4, GL_UNSIGNED_BYTE, back);
    glDrawElements(GL_QUADS, 4, GL_UNSIGNED_BYTE, left);
    
    
}

