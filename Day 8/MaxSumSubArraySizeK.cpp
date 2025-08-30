class Solution {
  public:
    int maximumSumSubarray(vector<int>& arr, int k) {
        int maxSum = 0;
        int curSum = 0;
        for (int i=0;i<k;i++){
            curSum += arr[i];
        }
        maxSum = curSum;
        
        for (int j=k;j<arr.size();j++){
            curSum = curSum + arr[j] - arr[j-k];
            if (maxSum<curSum){
                maxSum = curSum;
            }
        }
        
        return maxSum;
    }
};