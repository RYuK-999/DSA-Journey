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

    void helper(TreeNode* node, int targetSum, int currSum, vector<int> tempPath, vector<vector<int>> &answer){

        if (node == nullptr){
            return;
        }

        currSum += node->val;
        tempPath.push_back(node->val);

        if (node->left==nullptr && node->right==nullptr){
            if (currSum == targetSum){
                answer.push_back(tempPath);
            }
        }

        helper(node->left,targetSum,currSum,tempPath,answer);
        helper(node->right,targetSum,currSum,tempPath,answer);
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        
        vector<vector<int>> answer;
        int currSum = 0;
        vector<int> tempPath;

        helper(root,targetSum,currSum,tempPath,answer);

        return answer;
    }
};

// Using pass by reference as this would improve the time Complexity from O(n^2) to O(n)      :)
// The thing is when i am not passing any variable without reference, c++ makes a new copy of it and gives to next function call,
// now if the vector like here the tempPath becomes very big for example n size then copying will also take n time,
// now for every call the time complexity will increase as the tree is big like 1+2+3+4+ ... +n leading to n^2
// so if we combine this complexity with visiting nodes complexity i.e. O(n), overall it will be O(n^2)
// Therefore we use pass by reference so that copying thing can be removed and the answer can be obtained directly in O(n) times
// We didnt pass the currSum as pass by reference cause thats just 4 bytes and its always that size and it doesnt grow 
// hence there is no need to pass it as reference, we can simply keep it like that .
//  Yeah thats the overall idea to optimize this question ^-^




class Solution {
public:

    void helper(TreeNode* node, int targetSum, int currSum, vector<int> &tempPath, vector<vector<int>> &answer){

        if (node == nullptr){
            return;
        }

        currSum += node->val;
        tempPath.push_back(node->val);

        if (node->left==nullptr && node->right==nullptr){
            if (currSum == targetSum){
                answer.push_back(tempPath);
            }
        }

        helper(node->left,targetSum,currSum,tempPath,answer);
        helper(node->right,targetSum,currSum,tempPath,answer);
        tempPath.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        
        vector<vector<int>> answer;
        int currSum = 0;
        vector<int> tempPath;

        helper(root,targetSum,currSum,tempPath,answer);

        return answer;
    }
};