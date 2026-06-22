class KthLargest {
public:
    int k;
    priority_queue<int, vector<int>, greater<int>> pq;

    KthLargest(int k, vector<int>& nums) {
        this->k = k;

        for (int i=0;i<nums.size();i++){
            if (pq.size() == k){
                int value = pq.top();
                
                if (value < nums[i]){
                    pq.pop();
                    pq.push(nums[i]);
                }
            }
            else{
                pq.push(nums[i]);
            }
        }
    }
    
    int add(int val) {
        
        if (pq.size() < k){
            pq.push(val);
        }
        else{
            int topValue = pq.top();

            if (topValue < val){
                pq.pop();
                pq.push(val);
            }
        }

        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */



// More Simplified (gonna reduce the redundance work)

class KthLargest {
public:
    int k;
    priority_queue<int, vector<int>, greater<int>> pq;

    KthLargest(int k, vector<int>& nums) {
        this->k = k;

        for (int i=0;i<nums.size();i++){

            add(nums[i]);
        }
    }
    
    int add(int val) {
        
        if (pq.size() < k){
            pq.push(val);
        }
        else{
            int topValue = pq.top();

            if (topValue < val){
                pq.pop();
                pq.push(val);
            }
        }

        return pq.top();
    }
};
