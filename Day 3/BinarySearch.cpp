class Solution {
  public:
    int binarysearch(vector<int> &arr, int k) {
        int size = arr.size();
        int low = 0;
        int high = size-1;
        int answer = -1;
        
        while (low<=high){
            int mid = low+(high-low)/2;
            if (arr[mid]<k){
                low=mid+1;
            }
            if (arr[mid]>k){
                high=mid-1;
            }
            if (arr[mid]==k){
                answer = mid;
                high=mid-1;
            }
        }
        
        return answer;
    }
};