//
//  word_pattern_290.hpp
//  LinuxSystemAPI
//
//  Created by WuDi on 19/6/17.
//  Copyright © 2017 wu di. All rights reserved.
//

#ifndef word_pattern_290_hpp
#define word_pattern_290_hpp

#include <stdio.h>

#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>
#include <sstream>
using namespace std;

class word_pattern_290
{
public:
    word_pattern_290(){
        
    }
    
public:
    vector<string> splitBySpace(string s) {
        vector<string> result;
        
        std::istringstream iss(s);
        
        do
        {
            std::string sub;
            iss >> sub;
            if(sub != "")
                result.push_back(sub);
        } while (iss);
        return result;
    }
    
    bool wordPattern(string pattern, string str) {
        std::unordered_map<char, std::string> map;
        std::unordered_map<std::string, std::string> existed;
        
        vector<string> s = splitBySpace(str);
        if(s.size() != pattern.size()) return false;
        
        for(int i=0;i<pattern.size();i++) {
            char c = pattern[i];
            if(map.count(c) ) {
                
                if(map[c] != s[i])
                    return false;
            }
            else {
                if(existed.count(s[i]))
                    return false;
                
                existed[s[i]] = s[i];
                
                map[c] = s[i];
                
            }
        }
        
        return true;
        
    }
    
    void main_entry() {
        cout<<wordPattern("abba","dog dog dog dog")<<endl;
    }
    
};

#endif /* word_pattern_290_hpp */
