//
//  Mass.h
//  MoS Prog
//
//  Created by Adam Söderström on 2016-02-18.
//  Copyright (c) 2016 Adam Söderström. All rights reserved.
//

#ifndef __MoS_Prog__Mass__
#define __MoS_Prog__Mass__

#include <stdio.h>
#include <glm/glm.hpp>
#include <vector>

#endif /* defined(__MoS_Prog__Mass__) */

class Mass{
private:
    glm::vec3 pos;
    glm::vec3 velocity;
    
    //const glm::vec3 initPos;
    std::vector<int> connectedMasses;

    
public:
    glm::vec3 initialVelocity;
    glm::vec3 initialPos;
    
    int xCon;
    int yCon;
    int zCon;
    
    Mass(glm::vec3 _pos, glm::vec3 initVel) // : initPos(_pos)
    {
        initialPos = _pos;
        pos = _pos;
        
        initialVelocity=initVel;
        velocity=initialVelocity;
        
    }
    
    
    void setPosition(glm::vec3);
    glm::vec3 getPosition();
    
    void setVelocity(glm::vec3 vel);
    glm::vec3 getVelocity();
    
    void addConnection(int index);
    std::vector<int> getConnections();
    
};