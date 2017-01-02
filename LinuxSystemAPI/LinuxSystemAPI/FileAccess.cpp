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
#include <string.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <dirent.h>

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

void printdir(char *dir, int depth);
//@example: linux c - recursion for dir and file - printdir();
void FileAccess::recursive()
{
    printdir(".", 3);
}

void printdir(char *dir, int depth)
{
    DIR *dp;
    struct dirent *entry;
    struct stat statbuf;
    if((dp = opendir(dir)) == NULL) {
        fprintf(stderr,"cannot open directory: %s\n", dir);
        return;
    }
    chdir(dir);
    while((entry = readdir(dp)) != NULL) {
        lstat(entry->d_name,&statbuf);
        if(S_ISDIR(statbuf.st_mode)) {
            /* Found a directory, but ignore . and .. */
            if(strcmp(".",entry->d_name) == 0 ||
               strcmp("..",entry->d_name) == 0)
                continue;
            printf("%*s%s/\n",depth,"",entry->d_name);
            /* Recurse at a new indent level */
            printdir(entry->d_name,depth+4);
        }
        else printf("%*s%s\n",depth,"",entry->d_name);
    }
    chdir("..");
    closedir(dp);
}




void FileAccess::main()
{
    FileAccess s;
    //s.timeTest();
    //s.simple_write();
    s.recursive();
}