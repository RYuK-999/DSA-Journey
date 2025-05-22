class Solution {
  public:
    int getCount(string S, int N) {
        unordered_map<char,int> m;
        for (int i=0;i<S.length();i++){
            if (i==0 || S[i]!=S[i-1]){
                m[S[i]]++;
            }
            
        }
        
        int count =0;
        
        for (auto it:m){
            if(it.second==N){
                count++;
            }
        }
        
        return count;
    }
};