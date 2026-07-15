class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        
        vector<int> incoming(V,0);
        
        for (auto i: edges){
            incoming[i[1]]++;
        }
        
        vector<vector<int>> adj(V);
        
        for (auto i : edges){
            adj[i[0]].push_back(i[1]);
        }
        
        queue<int> q;
        
        for (int i=0;i<V;i++){
            if (incoming[i] == 0){
                q.push(i);
            }
        }
        
        vector<int> result;
        
        while (!q.empty()){
            int element = q.front();
            q.pop();
            
            result.push_back(element);
            
            for (auto i : adj[element]){
                incoming[i]--;
                
                if (incoming[i] == 0){
                    q.push(i);
                }
            }
        }
        
        return result;
    }
};