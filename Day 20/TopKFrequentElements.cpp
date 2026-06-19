class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int,int> mp;

        vector<int> answer;

        for (int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }

        vector<vector<int>> storage(nums.size()+1);

        for (auto &it : mp){
            storage[it.second].push_back(it.first);
        }

        for (int i=storage.size()-1;i>=0;i--){
            if (answer.size() != k){
                for (int j=0;j<storage[i].size();j++){
                    if (answer.size() != k){
                        answer.push_back(storage[i][j]);
                    }
                    else{
                        break;
                    }
                }
            }
            else{
                break;
            }
        }

        return answer;

    }
};


// Clean looking code :)

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int,int> mp;

        vector<int> answer;

        for (int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }

        vector<vector<int>> storage(nums.size()+1);

        for (auto &it : mp){
            storage[it.second].push_back(it.first);
        }

        for (int i=storage.size()-1; i>=0 && answer.size()!=k; i--){                       // Same code only little bit cleaning i did ^-^
            for (int j=0; j<storage[i].size() && answer.size()!=k; j++){
                answer.push_back(storage[i][j]);
            }
        }

        return answer;
    }
};