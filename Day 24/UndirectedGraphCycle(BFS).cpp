class Solution {
  public:
  
    bool isCycle(int V, vector<vector<int>>& edges) {
        
        vector<bool> visited(V,false);
        vector<vector<int>> adj(V);
        
        for (int i=0;i<edges.size();i++){
            
            if (edges[i][0] == edges[i][1]){                 // To handle Self-Loops
                return true;
            }
            
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        queue<pair<int,int>> q;
        
        for (int j=0;j<V;j++){
            if (!visited[j]){
                q.push({j,-1});
                visited[j] = true;
                
                while (!q.empty()){
                    pair<int,int> p = q.front();
                    q.pop();
        
                    for (auto i : adj[p.first]){
                        if (!visited[i]){
                            q.push({i,p.first});
                            visited[i] = true;
                        }
                        else{
                            if (i != p.second){
                                return true;
                            }
                        }
                    }
                }
            }
        }
        
        return false;
    }
};