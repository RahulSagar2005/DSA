#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
 int val;
 TreeNode *left;
 TreeNode *right;
TreeNode() : val(0), left(nullptr), right(nullptr) {}
TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    string tree2str(TreeNode* root) {
        if(root==NULL){
            return "";
        }
        string roots=to_string(root->val);
        string lefts=tree2str(root->left);
        string rights=tree2str(root->right);
        if(root->right==NULL && root->left==NULL){
            return roots;
        }
        if(root->left==NULL){
            return roots+"("+")"+"("+rights+")";
        }
        if(root->right==NULL){
            return roots+"("+ lefts+")";
        }
        return roots+"("+lefts+")"+"("+rights+")";        
    }
};