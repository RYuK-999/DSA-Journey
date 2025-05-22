class Solution {
  public:
    void reverseArray(vector<int> &arr) {
        int size = arr.size();
        int buffer = size-1;
        int i=0;
        while (i<buffer){
            swap(arr[i],arr[buffer]);
            i++;
            buffer--;
        }
    }
};