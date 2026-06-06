/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:

    TreeNode* helper(TreeNode* node, TreeNode* p, TreeNode* q){

        if (p->val > node->val && q->val > node->val){
            return helper(node->right,p,q);
        }
        else if (p->val < node->val && q->val < node->val){
            return helper(node->left,p,q);
        }
        else{
            return node;
        }
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        return helper(root,p,q);
        
    }
};

//Iterative Solution
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        TreeNode* curr = root;

        while (curr != nullptr){

            if (p->val > curr->val && q->val > curr->val){
                curr = curr->right;
            }
            else if (p->val < curr->val && q->val < curr->val){
                curr = curr->left;
            }
            else{
                return curr;
            }
        }

        return nullptr;
    }
};