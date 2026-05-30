class Solution {
  public:
  
    bool checking(vector<int> &stalls, int k, int mid){
        
        int i = 1;
        int placedCows = 1;               // Placing 1 cow initially at start
        int lastCowPosition = 0;          // Placed the first cow at first position hence index=0
        while (i<stalls.size()){
            int x = stalls[i] - stalls[lastCowPosition];
            if (x >= mid){
                placedCows++;
                lastCowPosition = i;
            }
            i++;
            
            if (placedCows == k){
                return true;
            }
        }
        return false;
    }
    
    int aggressiveCows(vector<int> &stalls, int k) {
        
        sort(stalls.begin(),stalls.end());
        int n = stalls.size();
        
        int low = 1;
        int high = stalls[n-1] - stalls[0];
        
        int ans = -1;
        
        while (low <= high){
            
            int mid = low + (high-low)/2;
            
            if (checking(stalls,k,mid)){
                ans = mid;
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        
        return ans;
    }
};