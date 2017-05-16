//
//  Leetcode_32.cpp
//  LinuxSystemAPI
//
//  Created by eddy.wu on 5/16/17.
//  Copyright © 2017 wu di. All rights reserved.
//

#include "Leetcode_32.hpp"

//@example: Leetcode 32. Longest Valid Parentheses - https://leetcode.com/problems/longest-valid-parentheses/#/description
int Leetcode_32::longestValidParentheses(string s) {
    
    int n= (int)s.length();
    
    if(n<=1) return 0;
    
    vector<int> x;

    x.push_back(0);
    for(int i=1;i<n;i++) {
        if(s[i] == ')') {
            if(x.size() > 0 && s[x.back()] == '(') {
                x.pop_back();
                continue;
            }
        }
        
           x.push_back(i);
    }
    
    if(x.size() == 0) return n;
    
    bool flag = true;
    
    int start = x[0];
    int max = x[0];
    
    for(int i=1;i<x.size();i++) {
        int t = x[i];
        int length = t - start;
        if(max < length) {
            max = length;
            flag = false;
        }
        
        start = t;
    }
    
    if(max < n - start) {
        max = n - start;
        flag = false;
    }
    
    if(flag)
        return max;
    
    return max - 1;
}
