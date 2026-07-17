class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<vector<int>> adj(numCourses);

        for (const auto& i : prerequisites){
            adj[i[1]].push_back(i[0]);
        }

        vector<int> need(numCourses);

        for (const auto& i : prerequisites){                     // Using Const auto& doesnt create copy of the specific vector it uses reference hence faster
            need[i[0]]++;
        }

        queue<int> q;

        for (int i=0;i<numCourses;i++){
            if (need[i] == 0){
                q.push(i);
            }
        }

        vector<int> result;

        while (!q.empty()){
            int element = q.front();
            q.pop();
            result.push_back(element);

            for (const auto& i : adj[element]){
                need[i]--;

                if (need[i] == 0){
                    q.push(i);
                }
            }
        }

        if (result.size() != numCourses){
            return {};                             // return vector<int>(); Same thing
        }

        return result;
    }
};