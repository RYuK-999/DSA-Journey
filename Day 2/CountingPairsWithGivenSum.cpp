class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        int count = 0;
        unordered_map<int,int> m;
        for (int i=0;i<arr.size();i++){
            int complement = target - arr[i];
            count+=m[complement];
            m[arr[i]]++;
            
        }
        return count;
        
    }
};