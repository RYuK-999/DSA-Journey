class Solution {
public:
    int mySqrt(int x) {
        
        if (x<1){
            return 0;
        }
        else if (x==1){
            return 1;
        }

        int low = 1;
        int high = x/2;
        int ans = -1;

        while (low <= high){
            int mid = low + (high-low)/2;

            if (mid == x/mid){              // here if we match something it returns directly that is the plus point 
                return mid;                 // for refernce u can check the gpt chat named Sqrt(x) in opryuk704
            }
            else if (mid > x/mid){
                high = mid-1;
            }
            else if (mid < x/mid){
                ans = mid;
                low = mid+1;
            }
        }
        return ans;
    }
};

// Eaiser and simpler way

class Solution {
public:
    int mySqrt(int x) {

        if (x == 0 || x == 1) {
            return x;
        }

        int low = 1;
        int high = x / 2;
        int ans = 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (mid <= x / mid) {
                ans = mid;      // valid candidate
                low = mid + 1;  // try to find a larger one
            }
            else {
                high = mid - 1; // mid is too large
            }
        }

        return ans;
    }
};