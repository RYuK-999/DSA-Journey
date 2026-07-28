class Solution {
public:
    string smallestPalindrome(string s) {
        
        vector<int> freq(26,0); 

        for (int i=0;i<s.size();i++){
            freq[s[i]-'a']++;
        }

        string middle = "";
        string leftHalf;

        for (int i=0;i<26;i++){
            int content = freq[i]/2;
            leftHalf.append(content,i+'a');

            if (freq[i] % 2 != 0){
                middle = i+'a';
            }
        }

        string rightHalf = leftHalf;

        reverse(rightHalf.begin(),rightHalf.end());

        string result = leftHalf + middle + rightHalf;

        return result;
    }
};