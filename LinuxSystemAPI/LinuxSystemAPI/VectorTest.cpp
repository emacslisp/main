//
//  VectorTest.cpp
//  LinuxSystemAPI
//
//  Created by eddy.wu on 10/16/17.
//  Copyright © 2017 wu di. All rights reserved.
//

#include "VectorTest.hpp"


void VectorTest::vectorTest() {
    int myints[]={10,20,30,40,50,60,70};
    std::vector<int> myvector (7);
    
    std::copy ( myints, myints+7, myvector.begin() );
    
    std::cout << "myvector contains:";
    for (std::vector<int>::iterator it = myvector.begin(); it!=myvector.end(); ++it)
        std::cout << ' ' << *it;
    
    std::cout << '\n';
}