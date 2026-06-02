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

    bool helper(TreeNode* node, long long int low, long long int high){
        
        if (node == nullptr){
            return true;
        }

        if (node->val > low && node->val < high){
            bool leftAnswer = helper(node->left,low,node->val);
            bool rightAnswer = helper(node->right,node->val,high);

            if (leftAnswer && rightAnswer){
                return true;
            }
        } 

        return false;
    }

    bool isValidBST(TreeNode* root) {
        
        long long int low = LLONG_MIN;
        long long int high = LLONG_MAX;

        return helper(root,low,high);
    }
};