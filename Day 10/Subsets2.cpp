class Solution {
public:

    void helper(vector<int> &nums, vector<vector<int>> &result, vector<int> &currentSubset,int index){

        result.push_back(currentSubset);

        for (int i=index;i<nums.size();i++){
            
            if (i>index && nums[i] == nums[i-1]){         // i>index means -> "Have I already tried another option before this one at the same recursion level?"   || “Am I still in the same decision level and seeing a repeated value?”
                continue;                                 // If yes -> skip it otherwise use it 
            }

            currentSubset.push_back(nums[i]);
            helper(nums,result,currentSubset,i+1);
            currentSubset.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> currentSubset;
        int index = 0;

        sort(nums.begin(),nums.end());

        helper(nums,result,currentSubset,index);

        return result;
    }
};

/*
For Subsets II, the main issue is duplicates. In normal subsets, we can use take/not-take for every index, but with duplicates like [1,2,2], blindly taking/not-taking both 2s can create the same subset multiple times. So we first sort the array, because sorting brings duplicate values together. Then we use for-loop backtracking, where each recursive call means: “from this index onward, what element can I choose next?” At every call, the current subset is already valid, so we immediately add it to the result. Then we loop from index to the end, choose one element, recurse with i + 1, and then pop it to backtrack.

The key duplicate rule is: if i > index and nums[i] == nums[i-1], we skip using continue. This means the same value is trying to start another branch at the same recursion level, which would create duplicate subsets. But if i == index, we allow it, even if it equals the previous value, because it is the first choice at this deeper level. That is why [2,2] is still possible. For example, after choosing the first 2, we call helper with index = 2; now i = 2, so i > index is false, and the second 2 is allowed.

So the idea is not “skip all duplicates.” The real idea is: skip duplicate values only when they are trying to create the same branch at the same level. continue removes that branch because it skips the push, recursive call, and pop for that duplicate option.
*/