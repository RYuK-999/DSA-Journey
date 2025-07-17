class Solution {
  public:
    vector<int> find(vector<int>& arr, int x) {
        int low = 0;
        int high = arr.size()-1;
        int firstPosi = -1;
        int lastPosi = -1;
        
        vector<int> ans;
        
        while (low<=high){
            int mid = low + (high-low)/2;
            
            if (arr[mid]<x){
                low = mid+1;
            }
            else if (arr[mid]>x){
                high = mid-1;
            }
            else if (arr[mid]==x){
                firstPosi=mid;
                high = mid-1;
            }
        }
        ans.push_back(firstPosi);
        
        
        int Low = 0;
        int High = arr.size()-1;
        
        while (Low<=High){
            int Mid = Low + (High-Low)/2;
            
            if (arr[Mid]<x){
                Low = Mid+1;
            }
            else if (arr[Mid]>x){
                High = Mid-1;
            }
            else if (arr[Mid]==x){
                lastPosi = Mid;
                Low = Mid+1;
            }
        }
        ans.push_back(lastPosi);
        
        return ans;
    }
};