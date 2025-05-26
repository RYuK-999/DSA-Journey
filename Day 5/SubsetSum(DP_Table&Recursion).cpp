// Using dp table

class Solution {
  public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        int rows = arr.size();
        vector<vector<bool>> dp(rows+1, vector<bool>(sum+1,false));
        
        dp [0][0] = true;
        
        for (int i=1;i<=rows;i++){
            for (int j=0;j<=sum;j++){
                dp[i][j]=dp[i-1][j];
                
                if (j-arr[i-1]>=0){
                    dp[i][j] = dp[i][j] | dp[i-1][j-arr[i-1]];
                }
            }
        }
        
        return dp[rows][sum];
    }
};

// Using Recursion

class Solution {
  public:
    
    bool helper(vector<int>& arr,int sum,int i){
        if (sum==0){
                return true;
        }
        if (i==0){
            return false;
        }
            
        if (arr[i-1]>sum){
            return helper(arr,sum,i-1);
        }
            
        return helper(arr,sum-arr[i-1],i-1) || helper(arr,sum,i-1);
    }
    
    bool isSubsetSum(vector<int>& arr, int sum){
        
        int i = arr.size();
        
        bool output = helper(arr,sum,i);
        
        return output;
    }
};