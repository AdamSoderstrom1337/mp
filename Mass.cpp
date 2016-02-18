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