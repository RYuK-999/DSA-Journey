class Solution {
  public:
    vector<int> firstNegInt(vector<int>& arr, int k) {
        vector<int> result;
        deque<int> dq;
        
        for (int i=0;i<k;i++){
            if (arr[i]<0){
                dq.push_back(i);
            }
        }
        if (!dq.empty()){
            result.push_back(arr[dq.front()]);
        }
        else{
            result.push_back(0);
        }
        
        for (int j=k;j<arr.size();j++){
            int start = j-k+1;
            int end = j;
            
            if (!dq.empty() && dq.front()<start){
                dq.pop_front();
            }
            
            if (arr[j]<0){
                dq.push_back(j);
            }
            
            if (!dq.empty()){
                result.push_back(arr[dq.front()]);
            }
            else{
                result.push_back(0);
            }
        }
        
        return result;
    }
};









//wrong i guess, its using vectors

class Solution {
  public:
    vector<int> firstNegInt(vector<int>& arr, int k) {
        vector<int> result;
        
        for (int i=0;i<k;i++){
            if (arr[i]<0){
                result.push_back(arr[i]);
            }
            else{
                result.push_back(0);
            }
        }
        
        for (int j=k;j<arr.size();j++){
            if (arr[j]<0){
                result.push_back(arr[j]);
            }
            else{
                result.push_back(0);
            }
        }
        return result;
        
    }
};