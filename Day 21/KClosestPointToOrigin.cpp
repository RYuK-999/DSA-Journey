class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        priority_queue<pair<int, pair<int,int>>> pq;
        
        vector<vector<int>> result;

        for (int i=0;i<points.size();i++){

            int newValue = 0;

            for (int j=0;j<2;j++){
                newValue += points[i][j]*points[i][j];
            }
            pair<int, pair<int,int>> newPair = {newValue, {points[i][0],points[i][1]}};

            if (pq.size() == k){
                int topValue = pq.top().first;

                if (topValue > newValue){
                    pq.pop();

                    pq.push(newPair);
                }
            }
            else{
                pq.push(newPair);
            }
        }

        while (!pq.empty()){

            pair<int, pair<int,int>> topPair = pq.top();

            pair<int,int> p = topPair.second;

            vector<int> answer;

            answer.push_back(p.first);
            answer.push_back(p.second);

            result.push_back(answer);
            pq.pop();
        }

        return result;
    }
};


// Made the code little bit clean :)

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        priority_queue<pair<int, pair<int,int>>> pq;
        
        vector<vector<int>> result;

        for (int i=0;i<points.size();i++){

            int newValue = points[i][0]*points[i][0] + points[i][1]*points[i][1];
        
            if (pq.size() == k){
                int topValue = pq.top().first;

                if (topValue > newValue){
                    pq.pop();

                    pq.emplace(newValue, pair<int,int>(points[i][0],points[i][1]));
                }
            }
            else{
                pq.emplace(newValue, pair<int,int>(points[i][0],points[i][1]));
            }
        }

        while (!pq.empty()){

            vector<int> answer = {pq.top().second.first,pq.top().second.second};

            result.push_back(answer);
            pq.pop();
        }

        return result;
    }
};