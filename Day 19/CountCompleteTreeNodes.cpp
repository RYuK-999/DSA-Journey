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

    int helper(TreeNode* node){

        if (node == nullptr){
            return 0;
        }

        TreeNode* temp1 = node->left;
        int leftHeightLS = 0;
        while (temp1 != nullptr){
            temp1 = temp1->left;
            leftHeightLS++;                    // left Height of Left Subtree (LS)
        }

        TreeNode* temp2 = node->right;
        int leftHeightRS = 0;
        while (temp2 != nullptr){
            temp2 = temp2->left;
            leftHeightRS++;                     // left height of Right Subtree (RS)
        }

        if (leftHeightLS == leftHeightRS){
            int value = pow(2,leftHeightLS) - 1 + 1 + helper(node->right);
            return value;
        }

        if (leftHeightLS > leftHeightRS){
            int value = pow(2,leftHeightRS) - 1 + 1 + helper(node->left);
            return value;
        }

        return 0;
    }

    int countNodes(TreeNode* root) {
        
        int result = helper(root);

        return result;
    }
};


/*
Count Complete Tree Nodes — Intuition

The key to this problem is to exploit the structure of a complete binary tree instead of traversing every node. 
A complete tree is filled level by level from left to right, which means if the leftmost path lengths of the left and right subtrees are equal, 
the left subtree must already be perfect; otherwise, the right subtree is perfect. 
A perfect subtree can be counted instantly using its height, so there is no need to visit every node inside it. 
The recursive function should answer only one question: 
"How many nodes are in the subtree rooted at this node?" At each step, identify the perfect subtree, count it in O(1) using its height, add the current node, and recurse only into the remaining imperfect subtree. 
Computing a height requires walking only one root-to-leaf path, which costs O(log n) because the height of a complete binary tree is logarithmic in the number of nodes. Since only one recursive call is made at each level, the overall complexity becomes O(log² n). 
The biggest lesson from this problem is to always look for structural properties that let you avoid work instead of optimizing work.
*/

// Another way using binary search

/*We would first calculate the total number of nodes in the level before the last level
then for the last level we can use binary search on answer and get the number of nodes in the last level
that way we can solve this question in another way
*/