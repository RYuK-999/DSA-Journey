class Solution {
  public:
  
    bool dfs(int element,int parent,vector<vector<int>> &adj, vector<bool> &visited){
        
        visited[element] = true;
        
        for (auto i : adj[element]){
            if (!visited[i]){
                if (dfs(i,element,adj,visited)){
                    return true;
                }
            }
            else{
                if (i != parent){
                    return true;
                }
            }
        }
        
        return false;
    }
  
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
        
        for (int i=0;i<V;i++){
            if (!visited[i]){
                if (dfs(i,-1,adj,visited)){
                    return true;
                }
            }
        }
        
        return false;
    }
};








Key insights:
- A visited neighbor is not always a cycle.
- The parent edge must be ignored.
- Need an outer loop for disconnected components.
- DFS naturally works on an adjacency list, not an edge list.
- Always inspect the graph representation before coding.
- Ask what assumptions the algorithm makes (simple graph? self-loops? parallel edges?).






