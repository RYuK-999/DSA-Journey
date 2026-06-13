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

    void helper(TreeNode* node, string tempPath, vector<string> &answer){

        if (node == nullptr){
            return;
        }

        tempPath.append(to_string(node->val));

        if (node->left==nullptr && node->right==nullptr){
            answer.push_back(tempPath);
        }

        tempPath.append("->");

        helper(node->left,tempPath,answer);
        helper(node->right,tempPath,answer);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        
        string tempPath;
        vector<string> answer;

        helper(root,tempPath,answer);

        return answer;
    }
};


// Using Pass By Reference    much cleaner and optimized code


class Solution {
public:

    void helper(TreeNode* node, vector<int> &tempPath, vector<string> &answer){

        if (node == nullptr){
            return;
        }

        tempPath.push_back(node->val);

        if (node->left==nullptr && node->right==nullptr){
            string temp = "";
            int size = tempPath.size();

            for (int i=0;i<size;i++){
                temp.append(to_string(tempPath[i]));
                if (i!=size-1){
                    temp.append("->");
                }
            }
            answer.push_back(temp);
        }

        helper(node->left,tempPath,answer);
        helper(node->right,tempPath,answer);

        tempPath.pop_back();
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        
        vector<int> tempPath;
        vector<string> answer;

        helper(root,tempPath,answer);

        return answer;
    }
};