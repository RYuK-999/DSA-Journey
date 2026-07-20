class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        
        int size = graph.size();
        vector<int> outgoing(size);

        for (int i=0;i<size;i++){
            outgoing[i] = graph[i].size();
        }

        vector<vector<int>> connection(size);
        for (int i=0;i<size;i++){
            for (auto j : graph[i]){
                connection[j].push_back(i);
            }
        }

        vector<bool> isSafe(size,false);
        queue<int> q;

        for (int i=0;i<size;i++){
            if (outgoing[i] == 0){
                q.push(i);
                isSafe[i] = true;
            }
        }

        while (!q.empty()){
            int element = q.front();
            q.pop();

            for (auto parent : connection[element]){
                outgoing[parent]--;

                if (outgoing[parent] == 0){
                    q.push(parent);
                    isSafe[parent] = true;
                }
            }
        }

        vector<int> result;
        for (int i=0;i<size;i++){
            if (isSafe[i]){
                result.push_back(i);
            }
        }

        return result;

    }
};