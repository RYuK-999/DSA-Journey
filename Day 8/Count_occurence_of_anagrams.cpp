//using unordered maps

class Solution {
  public:
    int search(string &pat, string &txt) {
        unordered_map<char,int> Pat;
        unordered_map<char,int> checking;
        
        for (int i=0;i<pat.length();i++){
            Pat[pat[i]]++;
        }
        
        int start = 0;
        int end;
        int count = 0;
        
        for (int j=0;j<pat.length();j++){
            checking[txt[j]]++;
        }
        if (Pat == checking){
            count++;
        }
        
        for (int end=pat.length();end<txt.length();end++){
            checking[txt[start]]--;
            if (checking[txt[start]]==0){
                checking.erase(txt[start]);
            }
            start++;
            
            checking[txt[end]]++;
            
            if (checking==Pat){
                count++;
            }
        }
        return count;
    }
};

//using arrray :  much more efficient

class Solution {
  public:
    bool isEqual(int a[],int b[]){
        for (int i=0;i<26;i++){
            if (a[i]!=b[i]){
                return false;
            }
        }
        return true;
    }
    int search(string &pat, string &txt) {
        int Pat[26] = {0};
        int checking[26] = {0};
        
        int count = 0;
        for (int i=0;i<pat.length();i++){
            Pat[pat[i]-'a']++;
        }
        
        for (int i=0;i<pat.length();i++){
            checking[txt[i]-'a']++;
        }
        if (isEqual(Pat,checking)){
            count++;
        }
        
        int start = 0;
        int end;
        for (end = pat.length();end<txt.length();end++){
            checking[txt[start]-'a']--;
            start++;
            checking[txt[end]-'a']++;
            if (isEqual(Pat,checking)){
                count++;
            }
        }
        return count;
    }
};