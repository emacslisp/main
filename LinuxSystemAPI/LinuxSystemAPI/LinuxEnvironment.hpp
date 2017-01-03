//
//  LinuxEnvironment.hpp
//  LinuxSystemAPI
//
//  Created by wu di on 17/1/4.
//  Copyright © 2017年 wu di. All rights reserved.
//

#ifndef LinuxEnvironment_hpp
#define LinuxEnvironment_hpp

#include <stdio.h>

class LinuxEnvironment
{
public:
    void getConsoleArg(int argc, const char *argv[]);
    
    void main(int argc, const char *argv[]);
};


#endif /* LinuxEnvironment_hpp */
