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

    int helper(TreeNode* node){

        if (node == nullptr){
            return 0;
        }

        int leftVal = helper(node->left);
        int rightVal = helper(node->right);

        int val = max(leftVal,rightVal);

        return val+1;
    }

    int maxDepth(TreeNode* root) {

        int answer = helper(root);

        return answer;
    }
};