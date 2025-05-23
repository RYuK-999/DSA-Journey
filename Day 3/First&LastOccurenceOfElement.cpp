class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size()-1;

        int firstPosi = -1;
        int lastPosi = -1;
        vector<int> ans;

        while (low<=high){
            int mid = low + (high-low)/2;

            if (nums[mid]<target){
                low = mid+1;
            }
            if (nums[mid]>target){
                high = mid-1;
            }
            if (nums[mid]==target){
                firstPosi = mid;
                high = mid-1;
            }
        }
        ans.push_back(firstPosi);

        int low1 = 0;
        int high1 = nums.size()-1;
        while (low1 <= high1){
            int mid1 = low1 + (high1-low1)/2;

            if (nums[mid1]<target){
                low1 = mid1 + 1;
            }
            if (nums[mid1]>target){
                high1 = mid1 - 1;
            }
            if (nums[mid1]==target){
                lastPosi = mid1;
                low1 = mid1 + 1;
            }
        }
        ans.push_back(lastPosi);

        return ans;
    }
};