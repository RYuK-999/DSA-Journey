/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    bool helper(TreeNode* a, TreeNode* b){

        if ( a==nullptr && b==nullptr){
            return true;
        }

        if ( a==nullptr && b!=nullptr){
            return false;
        }

        if ( a!=nullptr && b==nullptr){
            return false;
        }

        if ( a->val != b->val){
            return false;
        }

        if (!helper(a->left,b->right)){
            return false;
        }
        if (!helper(a->right,b->left)){
            return false;
        }

        return true;
    }

    bool isSymmetric(TreeNode* root) {
        
        if (root == nullptr){
            return true;
        }

        TreeNode* a = root->left;
        TreeNode* b = root->right;

        return helper(a,b);
    }
};


/*
 One more idea was that we can do traversal once with left root right and another time with right node left, and then compare the 
 values we store in array if its same its symmetry but the problem is it fails when we have all equal value nodes i mean all the 
 nodes are of same value there this way to solve fails.

 But still we can use this traversal technique but we have to store null as well cause storing null means we are storing 
 the value and structure of the tree as well which will help us determine if the tree is symmetric or not 
 whereas in the previous case we were only storing values hence we were losing the structure of tree.

 Yeah this is another way but the space complexity would be pretty high cause we are storing and then again we would compare and etc etc etc.
*/