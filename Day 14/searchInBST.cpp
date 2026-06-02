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

    TreeNode* helper(TreeNode* node, int val){

        if (node == nullptr){
            return nullptr;
        }

        if (node->val == val){
            return node;
        }

        if (val < node->val){
            return helper(node->left,val);
        }
        else if (val > node->val){
            return helper(node->right,val);
        }

        return nullptr;
    }

    TreeNode* searchBST(TreeNode* root, int val) {
        
        return helper(root,val);
    }
};