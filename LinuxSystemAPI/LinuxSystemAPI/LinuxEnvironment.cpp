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

void LinuxEnvironment::getOpt_longLib(int argc, char * argv[])
{
    int opt;
    
    struct option longopts[] = {
        {"initialize", 0, NULL, 'i'},
        {"file", 1, NULL, 'f'},
        {"list", 0, NULL, 'l'},
        {"restart", 0, NULL, 'r'},
        {0,0,0,0}};
    
    while((opt = getopt_long(argc, argv, "if:lr", longopts, NULL)) != -1) {
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

//@example: linux c - get environment lib
void LinuxEnvironment::getEnvLib()
{
    char *value;
    value = getenv("PATH");
    printf("%s\n",value);
}

//@example: linux c - environ api
void LinuxEnvironment::environLib()
{
    extern char **environ;
    
    char **env = environ;
    while(*env) {
        printf("%s\n",*env);
        env++;
    }
}

//@example: linux c - gmTime api lib
void LinuxEnvironment::gmTimeLib()
{
    struct tm *tm_ptr;
    time_t the_time;
    (void) time(&the_time);
    tm_ptr = gmtime(&the_time);
    printf("Raw time is %ld\n", the_time);
    printf("gmtime gives:\n");
    printf("date: %02d/%02d/%02d\n",
           tm_ptr->tm_year, tm_ptr->tm_mon+1, tm_ptr->tm_mday);
    printf("time: %02d:%02d:%02d\n",
           tm_ptr->tm_hour, tm_ptr->tm_min, tm_ptr->tm_sec);
}

void LinuxEnvironment::cTimeLib()
{
    time_t timeval;
    (void)time(&timeval);
    printf("The date is: %s", ctime(&timeval));
}

void LinuxEnvironment::strfTimeLib()
{
    struct tm *tm_ptr, timestruct;
    time_t the_time;
    char buf[256];
    char *result;
    (void) time(&the_time);
    tm_ptr = localtime(&the_time);
    strftime(buf, 256, "%A %d %B, %I:%S %p", tm_ptr);
    printf("strftime gives: %s\n", buf);
    strcpy(buf,"Sat 26 July 2003, 17:53 will do fine");
    printf("calling strptime with: %s\n", buf);
    tm_ptr = &timestruct;
    result = strptime(buf,"%a %d %b %Y, %R", tm_ptr);
    printf("strptime consumed up to: %s\n", result);
    printf("strptime gives:\n");
    printf("date: %02d/%02d/%02d\n",
           tm_ptr->tm_year % 100, tm_ptr->tm_mon+1, tm_ptr->tm_mday);
    printf("time: %02d:%02d\n",
           tm_ptr->tm_hour, tm_ptr->tm_min);
}

void LinuxEnvironment::main(int argc, char * argv[])
{
    LinuxEnvironment s;
    //s.getOpt_longLib(argc, argv);
    s.strfTimeLib();
}