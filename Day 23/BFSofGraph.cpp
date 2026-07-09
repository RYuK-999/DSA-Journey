class Solution {
  public:
    vector<int> bfs(vector<vector<int>> &adj) {
        
        queue<int> q;
        vector<int> result;
        
        vector<bool> visited(adj.size(),false);
        
        q.push(0);
        visited[0] = true;
        
        while (!q.empty()){
            int element = q.front();
            q.pop();
            
            result.push_back(element);
            
            for (int i : adj[element]){
                if (!visited[i]){
                    q.push(i);
                    visited[i] = true;
                }
            }
        }
        
        return result;
    }
};