class Solution {
public:

    void helper(int element, vector<bool> &visited, vector<vector<int>> &isConnected){
        visited[element] = true;

        for (int j=0;j<isConnected.size();j++){
            if ( element != j && isConnected[element][j] != 0 && visited[j] == false){
                helper(j,visited,isConnected);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        
        vector<bool> visited(isConnected.size(),false);
        int count = 0;

        for (int i=0;i<visited.size();i++){
            if (!visited[i]){
                count++;
                helper(i,visited,isConnected);
            }
        }

        return count;
    }
};