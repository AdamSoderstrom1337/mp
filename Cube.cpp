// glm::vec3
#include "Cube.h"
#include <iostream>


Cube::Cube(){
    
    /* Bottom */
    massVec.push_back(Mass(glm::vec3(0,0,0), glm::vec3(-1,-1,-1))); // BACK-BOT-LEFT
    massVec.push_back(Mass(glm::vec3(1,0,0), glm::vec3(1,-1,-1))); //BACK-BOT-RIGHT
    massVec.push_back(Mass(glm::vec3(1,0,1), glm::vec3(1,-1,1))); //FRONT-BOT-RIGHT
    massVec.push_back(Mass(glm::vec3(0,0,1), glm::vec3(-1,-1,1))); //FRONT-BOT-LEFT
    
    /* top */
    massVec.push_back(Mass(glm::vec3(0,1,0), glm::vec3(-1,1,-1))); // BACK-TOP-LEFT
    massVec.push_back(Mass(glm::vec3(1,1,0), glm::vec3(1,1,-1))); //BACK-TOP-RIGHT
    massVec.push_back(Mass(glm::vec3(1,1,1), glm::vec3(1,1,1))); //FRONT-TOP-RIGHT
    massVec.push_back(Mass(glm::vec3(0,1,1), glm::vec3(-1,1,1))); //FRONT-TOP-LEFT
    

    /* -- Add connections -- */
    
    massVec[0].xCon=1; //Mass 0
    massVec[0].yCon=4;
    massVec[0].zCon=3;
    massVec[0].xyzCon=6;

    massVec[1].xCon=0; //Mass 1
    massVec[1].yCon=5;
    massVec[1].zCon=2;
    massVec[1].xyzCon=7;
    
    massVec[2].xCon=3; //Mass 2
    massVec[2].yCon=6;
    massVec[2].zCon=1;
    massVec[2].xyzCon=4;

    
    massVec[3].xCon=2; //Mass 3
    massVec[3].yCon=7;
    massVec[3].zCon=0;
    massVec[3].xyzCon=5;

    
    massVec[4].xCon=5; //Mass 4
    massVec[4].yCon=0;
    massVec[4].zCon=7;
    massVec[4].xyzCon=2;

    
    massVec[5].xCon=4; //Mass 5
    massVec[5].yCon=1;
    massVec[5].zCon=6;
    massVec[5].xyzCon=3;

    
    massVec[6].xCon=7; //Mass 6
    massVec[6].yCon=2;
    massVec[6].zCon=5;
    massVec[6].xyzCon=0;
    
    massVec[7].xCon=6; //Mass 7
    massVec[7].yCon=3;
    massVec[7].zCon=4;
    massVec[7].xyzCon=1;

    
    /*-----------------------*/
    
}

void Cube::transBot(glm::vec3 _val){
    
    massVec[0].setPosition(massVec[0].getPosition()+_val);
    massVec[1].setPosition(massVec[1].getPosition()+_val);
    massVec[2].setPosition(massVec[2].getPosition()+_val);
    massVec[3].setPosition(massVec[3].getPosition()+_val);

    
}



void Cube::update(){


    
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
   
    float sign[3];
    glm::vec3 xyzSign;
    
    //Loop through masses
    
    glm::vec3 massXPos;
    glm::vec3 massYPos;
    glm::vec3 massZPos;
    glm::vec3 massXYZPos;
    
    for (int i=0; i<massVec.size(); i++){

        Mass massX=massVec[massVec[i].xCon];
        Mass massY=massVec[massVec[i].yCon];
        Mass massZ=massVec[massVec[i].zCon];
        Mass massXYZ=massVec[massVec[i].xyzCon];

        
        massXPos = massX.getPosition();
        massYPos = massY.getPosition();
        massZPos = massZ.getPosition();
        massXYZPos = massXYZ.getPosition();
        
        
        sign[0] = -glm::normalize((massXPos.x - massVec[i].getPosition().x));
        sign[1] = -glm::normalize((massYPos.y - massVec[i].getPosition().y));
        sign[2] = -glm::normalize((massZPos.z - massVec[i].getPosition().z));
        
        xyzSign.x= -glm::normalize(massXYZPos.x - massVec[i].getPosition().x);
        xyzSign.y= -glm::normalize(massXYZPos.y - massVec[i].getPosition().y);
        xyzSign.z= -glm::normalize(massXYZPos.z - massVec[i].getPosition().z);
        
              F[i]=k*(massXPos-massVec[i].getPosition()+sign[0]*sXlenght)
                    +d*(massX.getVelocity()-massVec[i].getVelocity());      //x-led
              F[i]+=k*(massYPos-massVec[i].getPosition()+sign[1]*sYlenght)
                    +d*(massY.getVelocity()-massVec[i].getVelocity())-m*g;    //y-led
              F[i]+=k*(massZPos-massVec[i].getPosition()+sign[2]*sZlenght)
                    +d*(massZ.getVelocity()-massVec[i].getVelocity());         //z-led
//        
//              F[i]+=k*(massXYZPos-massVec[i].getPosition()+xyzSign*sXYZlenght)
//                    +d*(massXYZ.getVelocity()-massVec[i].getVelocity()); // Diagonal feather
//        
//        
        //Floor collision
        if(massVec[i].getPosition().y+1< (float)std::abs(1e-1)){
            F[i]+=8*m*g;
        }
    }
    
    
    
    for (int i=0; i<massVec.size(); i++){
        massVec[i].setVelocity(massVec[i].getVelocity()+F[i]*h/m);
        massVec[i].setPosition(massVec[i].getPosition()+massVec[i].getVelocity()*h);
    
    }

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

void Cube::addExternalForce(){
    for (int i=4; i<massVec.size(); i++) {
        massVec[i].setVelocity(massVec[i].getVelocity()+glm::vec3(0.0f,-4.0f,0.0f));
    }

}

void Cube::jump(){
    if (massVec[0].getPosition().y<=-0.7) {
        for (int i=0; i<massVec.size(); i++) {
            massVec[i].setVelocity(massVec[i].getVelocity()+glm::vec3(0.0f,3.0f,0.0f));
        }
    }
}


void Cube::draw()
{
    int arrSize = massVec.size()*3;
    float vBuffer[arrSize];
    
    
    
    for(int i=0; i<massVec.size(); i++){
        float x = massVec[i].getPosition().x;
        float y = massVec[i].getPosition().y;
        float z = massVec[i].getPosition().z;
        
        vBuffer[(i*3)  ] = x;
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



glm::vec3 Cube::getCenter(){
    
    glm::vec3 avgPos= glm::vec3(0.0f, 0.0f, 0.0f);
    
    for(int i=0; i<massVec.size();i++)
    {
        avgPos+=massVec[i].getPosition();
    }
    
    avgPos/=(float)massVec.size();
    
    return avgPos;
}


