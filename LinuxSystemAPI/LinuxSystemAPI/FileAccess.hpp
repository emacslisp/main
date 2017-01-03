//
//  FileAccess.hpp
//  LinuxSystemAPI
//
//  Created by wu di on 16/12/31.
//  Copyright © 2016年 wu di. All rights reserved.
//

#ifndef FileAccess_hpp
#define FileAccess_hpp

#include <stdio.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <stdlib.h>

typedef struct {
    int integer;
    char string[24];
} RECORD;

class FileAccess
{
public:
    void timeTest();
    void main();
    void simple_write();
    
    void recursive();
    void mmapLib();
};

#endif /* FileAccess_hpp */
