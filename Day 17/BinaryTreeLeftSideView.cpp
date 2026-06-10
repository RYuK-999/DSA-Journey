/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
  
    void helper(Node* node, int depth, vector<int> &answer){
        
        if (node == nullptr){
            return;
        }
        
        if (depth == answer.size()){
            answer.push_back(node->data);
        }
        
        helper(node->left,depth+1,answer);
        helper(node->right,depth+1,answer);
    }
  
    vector<int> leftView(Node *root) {
        
        int depth = 0;
        vector<int> answer;
        
        helper(root,depth,answer);
        
        return answer;
    }
};

/*
The BFS Solution is also similar to the soultion we did in the right side view question, the only thing different is 
the array we make for every level in the right side view we take the right most element of that level here instead of rightmost 
we will take the left most element that is in the index 0 and save it, Thats it nothing much :)
*/