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
            TreeNode* newNode = new TreeNode(val);
            return newNode;
        }

        if (val < node->val){
            node->left = helper(node->left,val);
        }
        else if (val > node->val){
            node->right = helper(node->right,val);
        }

        return node;

    }

    TreeNode* insertIntoBST(TreeNode* root, int val) {
        
        return helper(root,val);
    }
};