//Normal Code

class Solution {
  public:
    int findMaxAverage(int arr[], int n, int k) {
        int maxSum = 0;
        int currentSum = 0;
        int index = 0;
        
        for (int i=0;i<k;i++){
            currentSum = currentSum + arr[i]; 
        }
        maxSum = currentSum;
        
        
        for (int i=k;i<n;i++){
            currentSum = currentSum + arr[i] - arr[i-k];
            if (maxSum<currentSum){
                maxSum=currentSum;
                index=i-k+1;
            }
        }
        
        return index;
        
        
        
    }
};


// Same but I kinda tweaked it a little 

class Solution {
  public:
    int findMaxAverage(int arr[], int n, int k) {
        int maxSum = 0;
        int currentSum = 0;
        int index = 0;
        
        for (int i=0;i<k;i++){
            currentSum = currentSum + arr[i]; 
        }
        maxSum = currentSum;
        
        
        for (int i=0;i<n-k;i++){
            currentSum = currentSum + arr[i+k] - arr[i];
            if (maxSum<currentSum){
                maxSum=currentSum;
                index=i+1;
            }
        }
        
        return index;
        
        
        
    }
};