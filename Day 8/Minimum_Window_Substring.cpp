//Efficient code

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> required;
        unordered_map<char,int> window;

        for (int i=0;i<t.length();i++){
            required[t[i]]++;
        }

        int left = 0;
        int right = 0;
        string result = "";

        int requiredTotal = required.size();
        int formed = 0;

        int min_length = INT_MAX;
        int start = 0;

        if (s.length()<t.length()){
            return result;
        }

        while (right<s.length()){
            char c = s[right];
            window[c]++;

            if (required.count(c) && window[c]==required[c]){
                formed++;
            }

            while (formed==requiredTotal){
                if (right-left+1<min_length){
                    min_length = min(min_length,right-left+1);
                    start = left;
                }

                char d = s[left];
                window[d]--;

                if (required.count(d) && window[d]<required[d]){
                    formed--;
                }
                left++;
            }
            right++;
        }

        if (min_length==INT_MAX){
            return result;
        }
        else{
            result = s.substr(start,min_length);
            return result;
        }
        
    }
};



//Very high time complexity cause we are checking again and again in isSubset


class Solution {
public:
    bool isSubset(unordered_map<char,int> a,unordered_map<char,int> b){
        bool value = true;
        for (auto pair : a){
            char key = pair.first;
            int val = pair.second;

            if (b.find(key)==b.end() || b[key]<val){
                value = false;
                break;
            } 
        }
        return value;
    }

    string minWindow(string s, string t) {
        unordered_map<char,int> required;
        unordered_map<char,int> window;

        for (int i=0;i<t.length();i++){
            required[t[i]]++;
        }

        int left = 0;
        int right = 0;
        string result = "";

        if (s.length()<t.length()){
            return result;
        }
        int minLength = INT_MAX;
        for (right=0;right<s.length();right++){
            window[s[right]]++;
            while (isSubset(required,window)){
                if (right-left+1<minLength){
                    minLength = right-left+1;
                    result = s.substr(left,right-left+1);
                }
                window[s[left]]--;
                left++;
            }
        }

        return result;
    }
};
