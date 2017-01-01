//
//  FileAccess.cpp
//  LinuxSystemAPI
//
//  Created by wu di on 16/12/31.
//  Copyright © 2016年 wu di. All rights reserved.
//

#include "FileAccess.hpp"
#include "time.h"
#include "unistd.h"

//@example: linux c - time api example
void FileAccess::timeTest()
{
    int i;
    time_t the_time;
    for(i=1;i<10;i++)
    {
        the_time = time((time_t *)0);
        
        printf("The time is %ld\n",the_time);
        sleep(2);
    }
}

//@example: linux c - write api
void FileAccess::simple_write()
{
    if(write(1,"Here is some data\n",18)!=18)
    {
        write(2,"test\n",5);
    }
}



void FileAccess::main()
{
    FileAccess s;
    s.timeTest();
    s.simple_write();
}