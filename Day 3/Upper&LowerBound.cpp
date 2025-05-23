// Upper Bound 

class Solution {
  public:
    int upperBound(vector<int>& arr, int target) {
        int low = 0;
        int high = arr.size()-1;
        int answer = arr.size();
        
        while (low<=high){
            int mid = low+(high-low)/2;
            
            if (arr[mid]<target){
                low = mid+1;
            }
            if (arr[mid]>target){
                answer = mid;
                high = mid-1;
            }
            if (arr[mid]==target){
                low = mid+1;
            }
        }
        
        return (answer);
        
    }
};

//Lower Bound

class Solution {
  public:
    int lowerBound(vector<int>& arr, int target) {
        int low = 0;
        int high = arr.size()-1;
        int answer = arr.size();
        
        while (low<=high){
            int mid = low + (high-low)/2;
            
            if (arr[mid]<target){
                low = mid+1;
            }
            if (arr[mid]>target){
                answer = mid;
                high = mid-1;
            }
            if (arr[mid]==target){
                answer = mid;
                high = mid-1;
            }
        }
        return answer;
    }
};