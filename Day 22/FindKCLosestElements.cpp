class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
        int left = 0;
        int right = arr.size()-k;

        while (left < right){
            int mid = left + (right-left)/2;

            int diffLeft = x - arr[mid];
            int diffRight = arr[mid+k] - x;

            if (diffLeft < diffRight){
                right = mid;
            }
            else if (diffLeft > diffRight){
                left = mid+1;
            }
            else if (diffLeft == diffRight){
                right = mid;
            }
        }

        vector<int> result;

        int count = 0;
        
        while (count != k){
            result.push_back(arr[left++]);
            count++;
        }
        

        return result;
    }
};