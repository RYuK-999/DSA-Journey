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

 // DFS Solution

class Solution {
public:

    void helper(TreeNode* node, vector<int> &answer, int depth){

        if (node == nullptr){
            return;
        }

        if (depth == answer.size()){
            answer.push_back(node->val);
        }

        helper(node->right,answer,depth+1);
        helper(node->left,answer,depth+1);
    }

    vector<int> rightSideView(TreeNode* root) {
        
        vector<int> answer;
        int depth = 0;

        helper(root, answer, depth);

        return answer;
    }
};

//BFS Solution

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        
        vector<int> answer;
        queue<TreeNode* > myQueue; 

        if (root == nullptr){
            return answer;
        }

        myQueue.push(root);

        while (!myQueue.empty()){

            int count = myQueue.size();

            for (int i=0;i<count;i++){
                TreeNode* temp = myQueue.front();

                if (i == count-1){
                    answer.push_back(temp->val);
                }
                myQueue.pop();

                if (temp->left){                            //This is written cause there is no problem in pushing a nullptr in pointer,its possible
                    myQueue.push(temp->left);               // but the problem is on the next iteration when we try to run the temp variable would get nullptr
                }                                           // and at that point if we do temp->val this will create issue cause nullptr doesnt have any value, that is the reason we use if statement here
                if (temp->right){
                    myQueue.push(temp->right);
                }
            }
        }
        return answer;
    }
};