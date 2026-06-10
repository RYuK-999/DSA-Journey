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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        
        if (p==nullptr && q==nullptr){
            return true;
        }

        if (p==nullptr && q!=nullptr){           
            return false;                     // These 2 false statements can also be combined and written as 
        }                                     //  if (p==nullptr || q==nullptr){
                                              //        return false;
        if (p!=nullptr && q==nullptr){        //  }                          Both null condition has been handled earlier so there's no problem
            return false;                                          // This is just to make the code much simpler and short nothing else
        }

        if (p->val != q->val){
            return false;
        }

        bool left = isSameTree(p->left,q->left);
        bool right = isSameTree(p->right,q->right);

        return (left && right);
    }
};