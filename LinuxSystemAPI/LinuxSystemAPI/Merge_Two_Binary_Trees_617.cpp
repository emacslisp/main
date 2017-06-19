//
//  Merge_Two_Binary_Trees_617.cpp
//  LinuxSystemAPI
//
//  Created by eddy.wu on 6/19/17.
//  Copyright © 2017 wu di. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
   int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Merge_Two_Binary_Trees {
public:
    Merge_Two_Binary_Trees() {
        
    }
    
    // https://leetcode.com/problems/merge-two-binary-trees/#/description
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        
        if(t1!=NULL && t2 !=NULL) {
            t1->val += t2->val;
        }
        else if(t1==NULL && t2!=NULL) {
            t1 = new TreeNode(t2->val);
        }
        else if(t1==NULL && t2==NULL)
        {
            return NULL;
        }
        else if(t1!=NULL && t2==NULL)
        {
            return t1;
        }
        
        if(t1->right == NULL && t2->right !=NULL) {
            t1->right = new TreeNode(0);
        }
        
        mergeTrees(t1->right, t2->right);
        
        
        if(t1->left == NULL && t2->left !=NULL) {
            t1->left = new TreeNode(0);
        }
        mergeTrees(t1->left, t2->left);
        
        return t1;
    }
    
    void main_entry() {
        TreeNode* t1 = NULL;
        TreeNode* t2 = new TreeNode(1);
        
        
       TreeNode* t3 = mergeTrees(t1,t2);
    }
};
