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

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        vector<vector<int>> result;
        queue<TreeNode* > myQueue;

        if (root == nullptr){
            return result;
        }
        
        myQueue.push(root);
        int level = 0;

        while (!myQueue.empty()){
            vector<int> temp;
            int size = myQueue.size();

            for (int i=0;i<size;i++){
                TreeNode* curr = myQueue.front();
                myQueue.pop();
                temp.push_back(curr->val);

                if (curr->left){
                    myQueue.push(curr->left);
                }
                if (curr->right){
                    myQueue.push(curr->right);
                }
            }

            if (level%2 != 0){
                reverse(temp.begin(),temp.end());
            }
        
            result.push_back(temp);

            level++;
        }

        return result;
    }
};