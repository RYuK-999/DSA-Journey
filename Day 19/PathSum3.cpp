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


// Brute Force

class Solution {
public:

    void helper1(TreeNode* node,int targetSum,long long int currSum, int &count){
        if (node == nullptr){
            return;
        }                                                                               //  helper1: Its responsibility is basically
                                                                                       //   "Every node deserves one chance to become the starting point."
        helper2(node,targetSum,currSum,count);
        helper1(node->left,targetSum,currSum,count);
        helper1(node->right,targetSum,currSum,count);
    }

    void helper2(TreeNode* node, int targetSum, long long int currSum, int &count){
        if (node == nullptr){
            return;
        }

        currSum += node->val;                                                         // helper2: single responsibility.
                                                                                      //  Starting from THIS node, explore every downward path.
        if (currSum == targetSum){
            count += 1;
        }

        helper2(node->left,targetSum,currSum,count);
        helper2(node->right,targetSum,currSum,count); 
    }

    int pathSum(TreeNode* root, int targetSum) {
        
        int count = 0;
        long long int currSum = 0;
        helper1(root,targetSum,currSum,count);

        return count;
    }
};


// Optimized way

class Solution {
public:

    void helper(TreeNode* node, int targetSum, long long int prefixSum, unordered_map<long long int,int> &map, int &count){
        if (node == nullptr){
            return;
        }

        prefixSum += node->val;

        if (map[prefixSum-targetSum]){
            count += map[prefixSum-targetSum];
        }
        map[prefixSum]++;

        helper(node->left,targetSum,prefixSum,map,count);
        helper(node->right,targetSum,prefixSum,map,count);

        map[prefixSum]--;
    }

    int pathSum(TreeNode* root, int targetSum) {
        
        int count = 0;
        long long int prefixSum = 0;
        unordered_map<long long int,int> map;
        map[0]++;
        helper(root,targetSum,prefixSum,map,count);

        return count;
    }
};

/* 
Key Invariant:

The unordered_map always stores the frequencies of prefix sums
ONLY on the current root-to-current DFS path.
*/

/*
So how this works, its a good question thats why i am writing here
    First of all the whole algorithm works like we reach a node then we ask what are the different paths could have led us to this
    place with the desired target, so what we do is every step we keep on saving the prefixSum in a map (cause it takes O(1) to fetch details from a map)

    so when we reach a specific node we subtract the required target with the current prefixSum and see if that value is available or not in the map,
    if its available we add that to the count what it means that when we are on that specific node the map tells us all the ancestors path that could lead us to the desired target,
    once we updated the value we put the current prefixValue to the map and then move on in the tree.

    Also putting map[0] is very important if we dont input it then the problem is that if there is a path from root->leaf which leads to targetSum we wont be able to save it.

*/

/* Much cleaner way what i was trying to say

So how this works (good question, so I'm writing it down ^-^ ):

The whole algorithm changes the perspective of the problem.

Instead of asking:

"From this node, where can I start?"

it asks:

"How many valid paths end at this node?"

During the DFS, we maintain the prefix sum from the root to the current node. We also keep an unordered_map that stores the frequency of every prefix sum on the current root-to-current path.

When we arrive at a node, we compute:
                                requiredPrefix = currentPrefix - target
If requiredPrefix exists in the map, it means there are one or more ancestor positions where a path starting immediately after that ancestor and ending at the current node has sum equal to target. The frequency tells us exactly how many such starting positions exist, so we add that frequency to our answer.
Only after checking do we insert the current prefix sum into the map. This prevents the current node from matching with itself.
While backtracking, we decrement the frequency of the current prefix sum because that prefix no longer belongs to the current DFS path. The map should always represent only the current root-to-current path, not prefix sums from previously explored branches.

Finally, we initialize the map with:
                                                    map[0] = 1;
This represents an imaginary prefix sum before the root. Without it, paths that start at the root and sum to target would never be counted.

*/