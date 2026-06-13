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

    bool helper(TreeNode* node, int targetSum, int currSum){

        if (node == nullptr){
            return false;
        }

        currSum += node->val;

        if (node->left == nullptr && node->right == nullptr){         // This thing can also be written like this: 
            if (currSum == targetSum){                                //    if (node->left == nullptr && node->right == nullptr){         
                return true;                                          //        return (currSum == targetSum);
            }                                                         //    }
            else{                                                     // 
                return false;                                         //  Just a simpler way to write it nothing else
            }
        }

        if (helper(node->left,targetSum,currSum)){
            return true;
        }

        if (helper(node->right,targetSum,currSum)){
            return true;
        }

        return false;
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        
        int currSum = 0;

        return helper(root,targetSum,currSum);
    }
};