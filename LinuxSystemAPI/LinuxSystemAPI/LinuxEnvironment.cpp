//
//  LinuxEnvironment.cpp
//  LinuxSystemAPI
//
//  Created by wu di on 17/1/4.
//  Copyright © 2017年 wu di. All rights reserved.
//

#include "LinuxEnvironment.hpp"

//@example: Linux c - get console argument using int argc, const char *argv[]
void LinuxEnvironment::getConsoleArg(int argc, const char *argv[])
{
    int arg;
    for(arg = 0; arg < argc; arg++) {
        if(argv[arg][0] == '-')
            printf("option: %s\n", argv[arg]+1);
        else
            printf("argument %d: %s\n", arg, argv[arg]);
    }
    
}

void LinuxEnvironment::main(int argc, const char *argv[])
{
    LinuxEnvironment s;
    s.getConsoleArg(argc, argv);
}