//
//  Mass.cpp
//  MoS Prog
//
//  Created by Adam Söderström on 2016-02-18.
//  Copyright (c) 2016 Adam Söderström. All rights reserved.
//

#include "Mass.h"


glm::vec3 Mass::getPosition(){
    return pos;
}

void Mass::setPosition(glm::vec3 _pos){
    pos=_pos;
}

void Mass::addConnection(int index){
    connectedMasses.push_back(index);
}

void Mass::setVelocity(glm::vec3 vel){
    velocity=vel;
}

glm::vec3 Mass::getVelocity(){
    return velocity;
}

std::vector<int> Mass::getConnections(){
    return connectedMasses;
}

