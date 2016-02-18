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

#endif /* defined(__MoS_Prog__Mass__) */

class Mass{
private:
    glm::vec3 pos;
    const glm::vec3 initPos;
    
public:
    Mass(glm::vec3 _pos) : initPos(_pos)
    {
        pos = _pos;
    }
    
    void setPosition(glm::vec3);
    glm::vec3 getPosition();
    
    
    
};