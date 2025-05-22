//code 1

class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());

        if (s==t){
            return true;
        }
        else{
            return false;
        }
    }
};

//code 2

class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> m;
        if (s.length()!=t.length()){
            return false;
        }
        for (int i=0;i<s.length();i++){
            m[s[i]]++;
        }

        for (int j=0;j<t.length();j++){
            m[t[j]]--;
        }

        for (auto it:m){
            if (it.second!=0){
                return false;
            }
        }
        return true;
    }
};