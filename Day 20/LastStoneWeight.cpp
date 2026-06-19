class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        
        priority_queue<int> pq;

        for (int i=0;i<stones.size();i++){
            pq.push(stones[i]);
        }

        // Can also be used to create a heap directly from the vector
        // priority_queue<int> pq(stones.begin(),stones.end());
        // The time complexity for this is cheaper O(n)
        // Where as for the push thing time complexity is O(nlogn)

        while (pq.size() > 1){
            int y = pq.top();
            pq.pop();
            int x = pq.top();
            pq.pop();

            if (x != y){
                int value = y-x;
                pq.push(value);
            }
        }

        if (!pq.empty()){
            return pq.top();
        }

        return 0;
    }
};