class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int j=0;
        vector<int> temp;
        for (int a=0;a<nums.size();a++){
            temp.push_back(nums[a]);
        }

        int size = nums.size();
        k=k%size;
        
        for (int i=size-k;i<size;i++){
            nums[j]=nums[i];
            j++;
        }
        for (int i=0;i<size-k;i++){
            nums[j]=temp[i];
            j++;
        }
    }
};