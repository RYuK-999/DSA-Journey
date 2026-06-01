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
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        vector<vector<int>> result;

        if (root == nullptr){
            return result;
        }

        queue<TreeNode* > myQueue;
        myQueue.push(root);

        while (!myQueue.empty()){
            int count = myQueue.size();
            vector<int> tempStorage;

            for (int i=0;i<count;i++){
                TreeNode* temp = myQueue.front();
                myQueue.pop();

                if (temp->left){
                    myQueue.push(temp->left);
                }
                if (temp->right){
                    myQueue.push(temp->right);
                }

                tempStorage.push_back(temp->val);
            }

            result.push_back(tempStorage);
        }

        return result;
    }
};


//DFS way to solve

class Solution {
public:
    void dfs(TreeNode* node, int level, vector<vector<int>>& result) {

        if (node == nullptr) {
            return;
        }

        if (level == result.size()) {
            result.push_back(vector<int>());
        }

        result[level].push_back(node->val);

        dfs(node->left, level + 1, result);
        dfs(node->right, level + 1, result);
    }

    vector<vector<int>> levelOrder(TreeNode* root) {

        vector<vector<int>> result;

        dfs(root, 0, result);

        return result;
    }
};