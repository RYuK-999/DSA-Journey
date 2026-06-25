class Solution {
public:
    string frequencySort(string s) {
        
        priority_queue<pair<int,char>> heap;
        unordered_map<char,int> freq;
        string result;

        for (char c : s){
            freq[c]++;
        }

        for (auto it : freq){
            pair<int,char> p = {it.second,it.first};

            heap.push(p);
        }

        while (!heap.empty()){
            pair<int,char> p = heap.top();

            for (int i=0;i<p.first;i++){
                result.push_back(p.second);
            }

            heap.pop();
        }

        return result;
    }
};