class Solution {
  public:
    int countFreq(vector<int>& arr, int target) {
        int low = 0;
        int high = arr.size()-1;
        int FirstPosi = -1;
        int LastPosi = -1;
        
        while (low<=high){
            int mid = low + (high-low)/2;
            
            if (arr[mid]>target){
                high = mid-1;
            }
            else if (arr[mid]<target){
                low = mid+1;
            }
            else if (arr[mid]==target){
                FirstPosi = mid;
                high = mid-1;
            }
        }
        
        int Low = 0;
        int High = arr.size()-1;
        
        while (Low<=High){
            int Mid = Low + (High-Low)/2;
            
            if (arr[Mid]>target){
                High = Mid-1;
            }
            else if (arr[Mid]<target){
                Low = Mid+1;
            }
            else if (arr[Mid]==target){
                LastPosi = Mid;
                Low = Mid+1;
            }
        }
        
        if (FirstPosi == -1 || LastPosi == -1){
            return 0;
        }
        
        int occurrence = LastPosi-FirstPosi+1;
        return occurrence;
    }
};