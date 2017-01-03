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


//@example: linux c - mmap to sync memory and file 
void FileAccess::mmapLib()
{
    #define NRECORDS (100)
    
    RECORD record, *mapped;
    int i, f;
    FILE *fp;
    fp = fopen("records.dat","w+");
    for(i=0; i<NRECORDS; i++) {
        record.integer = i;
        sprintf(record.string,"RECORD-%d",i);
        fwrite(&record,sizeof(record),1,fp);
    }
    fclose(fp);
    
    f = open("records.dat",O_RDWR);
    mapped = (RECORD *)mmap(0, NRECORDS*sizeof(record),
                            PROT_READ|PROT_WRITE, MAP_SHARED, f, 0);
    mapped[43].integer = 243;
    sprintf(mapped[43].string,"RECORD-%d",mapped[43].integer);
    msync((void *)mapped, NRECORDS*sizeof(record), MS_ASYNC);
    munmap((void *)mapped, NRECORDS*sizeof(record));
    close(f);
    printf("mmap done!!");
    exit(0);
}


void FileAccess::main()
{
    FileAccess s;
    //s.timeTest();
    //s.simple_write();
    s.mmapLib();
}