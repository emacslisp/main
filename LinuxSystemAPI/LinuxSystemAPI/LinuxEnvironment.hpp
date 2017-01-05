//
//  LinuxEnvironment.hpp
//  LinuxSystemAPI
//
//  Created by wu di on 17/1/4.
//  Copyright © 2017年 wu di. All rights reserved.
//

#ifndef LinuxEnvironment_hpp
#define LinuxEnvironment_hpp

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>

class LinuxEnvironment
{
public:
    void getConsoleArg(int argc, const char *argv[]);
    void getOptApiLib(int argc, char * const argv[]);
    
    void getOpt_longLib(int argc, char * argv[]);

    void getEnvLib();
    
    void environLib();
    
    void gmTimeLib();

    void cTimeLib();
    
    void strfTimeLib();
    
    void tempFileLib();
    
    void userLib();
    
    void hostNameLib();
    
    void logMaskLib();
    
    void main(int argc, char * argv[]);
};


#endif /* LinuxEnvironment_hpp */
