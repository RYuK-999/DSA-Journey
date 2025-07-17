//  For Floor 

class Solution {
  public:
    int findFloor(vector<int>& arr, int x) {
        int low = 0;
        int high = arr.size()-1;
        int Floor = -1;
        
        while (low<=high){
            int mid = low + (high-low)/2;
            
            if (arr[mid]>x){
                high = mid-1;
            }
            else if (arr[mid]<=x){
                Floor = mid;
                low = mid+1;
            }
        }
        
        return Floor;
    }
};

// For Ceil

class Solution {
  public:
    int findCeil(vector<int>& arr, int x) {
        int low = 0;
        int high = arr.size()-1;
        int Ceil = -1;
        
        while (low<=high){
            int mid = low + (high-low)/2;
            
            if (arr[mid]<x){
                low = mid+1;
            }
            else if (arr[mid]>=x){
                Ceil = mid;
                high = mid-1;
            }
        }
        
        return Ceil;
    }
};