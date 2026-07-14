class Solution {
  public:
  
    void dfs(int element, vector<vector<int>> &adj, vector<bool> &visited, vector<int> &current){
        
        visited[element] = true;
        current.push_back(element);
        
        for (auto i : adj[element]){
            if (!visited[i]){
                dfs(i,adj,visited,current);
            }
        }
    }  
  
    vector<vector<int>> getComponents(int V, vector<vector<int>>& edges) {
        
        vector<vector<int>> adj(V);
        
        for (int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        vector<bool> visited(V,false);
        
        vector<vector<int>> result;
        
        for (int i=0;i<visited.size();i++){
            vector<int> current;
            if (!visited[i]){
                dfs(i,adj,visited,current);
                result.push_back(current);
            }
            
        }
        
        return result;
    }
};
