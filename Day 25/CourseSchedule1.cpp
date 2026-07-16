class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<vector<int>> adj(numCourses);

        for (auto i : prerequisites){
            adj[i[1]].push_back(i[0]);
        }

        vector<int> need(numCourses,0);
        for (auto i : prerequisites){
            need[i[0]]++;
        }

        queue<int> q;
        for (int i=0;i<numCourses;i++){
            if (need[i] == 0){
                q.push(i);
            }
        }

        int count = 0;
        while (!q.empty()){
            int element = q.front();
            q.pop();
            count++;

            for (auto i : adj[element]){
                need[i]--;

                if (need[i] == 0){
                    q.push(i);
                }
            }
        }

        if (count == numCourses){
            return true;
        }
        
        return false;
    }
};