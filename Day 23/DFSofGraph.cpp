class Solution {
  public:
  
    void helper(int element,vector<bool> &visited, vector<int> &result, vector<vector<int>> &adj){
        
        visited[element] = true;
        result.push_back(element);
        
        for (auto it : adj[element]){
            if (!visited[it]){
                helper(it,visited,result,adj);
            }
        }
    }
    
  
    vector<int> dfs(vector<vector<int>>& adj) {
        
        vector<bool> visited(adj.size(),false);
        
        vector<int> result;
        
        helper(0,visited,result,adj);
        
        return result;
    }
};