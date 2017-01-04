//
//  LinuxEnvironment.cpp
//  LinuxSystemAPI
//
//  Created by wu di on 17/1/4.
//  Copyright © 2017年 wu di. All rights reserved.
//

#include "LinuxEnvironment.hpp"
#include <stdio.h>
#include <unistd.h>
#include <getopt.h>

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


//@example: c++ - const char* and char const * and char* const
/*
 int       *      mutable_pointer_to_mutable_int;
 int const *      mutable_pointer_to_constant_int;
 int       *const constant_pointer_to_mutable_int;
 int const *const constant_pointer_to_constant_int;
 */

//@example: linux c - getopt with optarg
void LinuxEnvironment::getOptApiLib(int argc,  char * const argv[])
{
    int opt;
    const char *p = "if:lr";
    
    while((opt = getopt(argc, argv, p)) != -1) {
        switch(opt) {
            case 'i':
            case 'l':
            case 'r':
                printf("option: %c\n", opt);
                break;
            case 'f':
                printf("filename: %s\n", optarg);
                break;
            case ':':
                printf("option needs a value\n");
                break;
            case '?':
                printf("unknown option: %c\n", optopt);
                break;
        }
    }
    for(; optind < argc; optind++)
        printf("argument: %s\n", argv[optind]);
}

void LinuxEnvironment::main(int argc, char * argv[])
{
    LinuxEnvironment s;
    s.getOptApiLib(argc, argv);
}