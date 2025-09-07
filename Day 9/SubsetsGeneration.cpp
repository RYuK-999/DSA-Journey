class Solution {
public:
    void generate(vector<int>& nums,int index,vector<int>& currentSubset,vector<vector<int>>& result){

        if (index==nums.size()){
            result.push_back(currentSubset);
            return;
        }

        currentSubset.push_back(nums[index]);
        generate(nums,index+1,currentSubset,result);
        currentSubset.pop_back();

        generate(nums,index+1,currentSubset,result);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> currentSubset;
        int index = 0;

        generate(nums,index,currentSubset,result);

        return result;
    }
};


/* Overall tree how it works

Call: index=0, currentSubset=[]
├── Include 1 → currentSubset=[1], index=1
│   ├── Include 2 → currentSubset=[1,2], index=2
│   │   ├── Include 3 → currentSubset=[1,2,3], index=3 → store [1,2,3]
│   │   └── Exclude 3 → currentSubset=[1,2], index=3 → store [1,2]
│   └── Exclude 2 → currentSubset=[1], index=2
│       ├── Include 3 → currentSubset=[1,3], index=3 → store [1,3]
│       └── Exclude 3 → currentSubset=[1], index=3 → store [1]
└── Exclude 1 → currentSubset=[], index=1
    ├── Include 2 → currentSubset=[2], index=2
    │   ├── Include 3 → currentSubset=[2,3], index=3 → store [2,3]
    │   └── Exclude 3 → currentSubset=[2], index=3 → store [2]
    └── Exclude 2 → currentSubset=[], index=2
        ├── Include 3 → currentSubset=[3], index=3 → store [3]
        └── Exclude 3 → currentSubset=[], index=3 → store []

*/
