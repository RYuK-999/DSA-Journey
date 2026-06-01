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

    int helper(TreeNode* node, int &maxHeight){
        
        if (node == nullptr){
            return 0;
        }

        int leftHeight = helper(node->left, maxHeight);
        int rightHeight = helper(node->right, maxHeight);

        int currentDiameter = leftHeight + rightHeight;
        if (currentDiameter > maxHeight){
            maxHeight = currentDiameter;
        }

        return max(leftHeight,rightHeight) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        
        int maxHeight = -1;

        helper(root,maxHeight);

        return maxHeight;
    }
};