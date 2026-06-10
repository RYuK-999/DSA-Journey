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

        if (node == nullptr){
            return nullptr;
        }

        if (node == p){
            return p;
        }

        if (node == q){
            return q;
        }

        TreeNode* l = helper(node->left,p,q);
        TreeNode* r = helper(node->right,p,q);

        if (l==nullptr && r!=nullptr){
            return r;
        }

        if (l!=nullptr && r==nullptr){
            return l;
        }

        if (l!=nullptr && r!=nullptr){
            return node;
        }

        return nullptr;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        return helper(root,p,q);
    }
};


/*
Ok so how i solved it and how is it working (I know i am just writing this for myself cause it is a good question hehe)\

The nodes can be of any value cause its a binary tree so no fixed tree rule here, so what we do we noramlly the bigger idea is that
a node would be there we will try to see its left and right subtree, if both sides return something important (important means they found either p or q), 
then both targets have been accounted for through different directions, therefore the current node becomes the LCA. 
and we just simply pass that node to upper trees without thinking much.

Now the thing is the return value that we are passing to upper parts of the tree (i mean the ancestors) doesnt has to know if its p or q
or its lca they just only need to check if its something important then just pass it upwards (no questions asked) in this way the 
whole tree can give the proper lca value.

Now the main thing what if the tree is like      4
                                                /
                                                3               and the value of p and q is lets take 4 and 2.
                                               /
                                               2                

Now in this case also we hit 4 first we directly pass it upward as important information we dont even need to go deep without even checking 
that if under node 4 do we even have node 2 (i.e. q) is present or not, cause its given in the question description that both p and q 
would be present no matter what hence this case was directly able to solve it without any problem. (Now if p or q may be present or absent would be a different story).

So the main idea is what is the thing that we are returning at the end of the day, It is just a value that is something important 
and we receive it from lower parts thats the whole concept, the upper ancestors just look at it and like "Hmm this is important lets pass it upwards doesnt matter what is it idgaf"
Yeah thats the whole idea
*/