//Using set

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLength = 0;
        set<char> Char;
        int start = 0;
        int end = 0;

        for (int end=0;end<s.length();end++){
            if (!Char.count(s[end])){
                Char.insert(s[end]);
                maxLength = max(maxLength,end-start+1);
            }
            else{
                while (Char.count(s[end])){
                    Char.erase(s[start]);
                    start++;
                }
                Char.insert(s[end]);
                
            }
        }
        return maxLength;
    }
};

//using unordered map

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> lastSeen;
        int start = 0;
        int maxLength = 0;
        int end = 0;                                                 //max(start, lastSeen[s[end]] + 1) ensures:
                                                                     //1.If the duplicate character is inside the current window, we move start just past the duplicate.
                                                                    //2.If the duplicate was outside the current window, we do nothing.
                                                                    //3. So start only moves forward or stays the same — never backward.
        for (end=0;end<s.length();end++){
            if (!lastSeen.count(s[end])){
                lastSeen[s[end]]=end;
            }
            else{
                start = max(start,lastSeen[s[end]]+1);
                lastSeen[s[end]]=end;
            }
            maxLength = max(maxLength,end-start+1);
        }
        return maxLength;
    }
};