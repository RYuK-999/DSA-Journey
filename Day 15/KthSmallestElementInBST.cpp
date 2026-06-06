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

    void helper(TreeNode* node, int k, int &answer, int &count){
        
        if (node == nullptr){
            return;
        }

        if (count == k){
            return;
        }

        helper(node->left,k,answer,count);
        if (count == k){                                 // To check again if the left subtree has found the answer or not
            return;
        }

        count++;
        
        if (count == k){
            answer = node->val;
            return;
        }
        helper(node->right,k,answer,count);
    }

    int kthSmallest(TreeNode* root, int k) {
        
        int answer;
        int count = 0;

        helper(root,k,answer,count);

        return answer;
    }
};

//Much better and clean asf

class Solution {
public:

    bool helper(TreeNode* node, int k, int &answer, int &count){
        
        if (node == nullptr){
            return false;
        }

        if (helper(node->left,k,answer,count)){
            return true;
        }
        count++;
        if (count == k){
            answer = node->val;
            return true;
        }
        if (helper(node->right,k,answer,count)){
            return true;
        }

        return false;
    }

    int kthSmallest(TreeNode* root, int k) {
        
        int answer;
        int count = 0;

        helper(root,k,answer,count);

        return answer;
    }
};