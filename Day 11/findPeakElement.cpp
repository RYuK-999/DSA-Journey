class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        
        int n = nums.size();

        if (n==1){
            return 0;
        }

        if (nums[0] > nums[1]){
            return 0;
        }
        if (nums[n-1] > nums[n-2]){
            return n-1;
        }

        int low = 1;
        int high = n-2;

        while (low <= high){
            int mid = low + (high-low)/2;

            if (nums[mid] > nums[mid+1] && nums[mid] > nums[mid-1]){
                return mid;
            }
            else if (nums[mid] > nums[mid-1]){
                low = mid+1;
            }
            else if (nums[mid] > nums[mid+1]){
                high = mid-1;
            }
            else{                                       // Using this statement to check any valley condition :)
                high = mid-1;                            // example:  5  2  4  
            }                                           // There is no restriction we can either move left or right it depends on us
        }

        return -1;
    }
};


// Simplified code

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;

        while (low < high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] < nums[mid + 1]) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }

        return low;
    }
};