class Solution {
  public:
  
    bool checking(vector<int> &arr, int k, int mid){
        
        int studentUsed = 1;
        int currentPages = 0;
        int i = 0;
        
        while (i<arr.size()){
            if (currentPages + arr[i] <= mid){
                currentPages += arr[i];
                i++;
            }
            else{
                studentUsed++;
                currentPages = arr[i];
                i++;
            }
        }
        
        return studentUsed <= k ? true : false;
        
        /*
        if (studentUsed <= k){
            return true;
        }
        else{
            return false;
        }
        */
    }
    
    int findPages(vector<int> &arr, int k) {
        
        int n = arr.size();
        
        if (k>n){                   // No of Students is greater than no of books not possible
            return -1;
        }
        
        int totalPages = 0;
        int highestPages = -1;
        for (int i=0;i<arr.size();i++){
            totalPages += arr[i];
            if (arr[i] > highestPages){
                highestPages = arr[i];
            }
        }
        
        int ans = -1;
        
        int low = highestPages;
        int high = totalPages;
        
        while (low <= high){
            
            int mid = low + (high-low)/2;
            
            if (checking(arr,k,mid)){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        
        return ans;
    }
};





// little optimized and efficient :)

class Solution {
public:

    bool checking(vector<int>& arr, int k, int mid) {

        int studentUsed = 1;
        int currentPages = 0;

        for (int i = 0; i < arr.size(); i++) {

            if (arr[i] > mid) {
                return false;
            }

            if (currentPages + arr[i] <= mid) {
                currentPages += arr[i];
            }
            else {
                studentUsed++;
                currentPages = arr[i];

                if (studentUsed > k) {
                    return false;
                }
            }
        }

        return true;
    }

    int findPages(vector<int>& arr, int k) {

        int n = arr.size();

        if (k > n) {
            return -1;
        }

        int totalPages = 0;
        int highestPages = 0;

        for (int pages : arr) {
            totalPages += pages;
            highestPages = max(highestPages, pages);
        }

        int low = highestPages;
        int high = totalPages;
        int ans = -1;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            if (checking(arr, k, mid)) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return ans;
    }
};