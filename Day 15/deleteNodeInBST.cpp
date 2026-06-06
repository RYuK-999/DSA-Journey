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

    TreeNode* helper(TreeNode* node, int key){

        if (node == nullptr){
            return node;
        }

        if (key < node->val){
            node->left =  helper(node->left, key);
            return node;
        }
        else if (key > node->val){
            node->right = helper(node->right, key);
            return node;
        }
        else{
            if (node->left == nullptr && node->right == nullptr){
                return nullptr;
            }
            else if (node->left != nullptr && node->right == nullptr){
                return node->left;
            }
            else if (node->left == nullptr && node->right != nullptr){
                return node->right;
            }
            else{
                TreeNode* element = node->left;
                while (element->right != nullptr){
                    element = element->right;
                }

                node->val = element->val;
                node->left = helper(node->left, node->val);

                return node;
            }
        }
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        
        return helper(root, key);
    }
};