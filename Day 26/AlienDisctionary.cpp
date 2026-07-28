class Solution {
  public:
    string findOrder(vector<string> &words) {
        
        vector<set<char>> adj(26);
        vector<int> indegree(26);
        vector<bool> visited(26,false);
        
        for (auto i : words){
            for (auto letter : i){
                visited[letter-'a'] = true;
            }
        }
        
        for (int i = 0;i<words.size()-1;i++){
            bool isChanged = false;
            for (int j=0;j<min(words[i].size(),words[i+1].size());j++){
                if (words[i][j] != words[i+1][j]){
                    isChanged = true;
                    auto happened = adj[words[i][j]-'a'].insert(words[i+1][j]);
                    
                    if (happened.second == true){
                        indegree[words[i+1][j]-'a']++;
                    }
                    break;
                }
            }
            
            int sizeFirst = words[i].size();
            int sizeSecond = words[i+1].size();
            
            if (!isChanged && sizeFirst > sizeSecond){
                return "";
            }
            
            
        }
        
        int alphabets = count(visited.begin(),visited.end(),true);
        
        string result;
        queue<char> q;
        
        for (int i=0;i<26;i++){
            if (indegree[i]==0 && visited[i]){
                q.push(i+'a');
            }
        }
        
        while (!q.empty()){
            char element = q.front();
            result.push_back(element);
            q.pop();
            
            for (auto i : adj[element-'a']){
                indegree[i-'a']--;
                
                if (indegree[i-'a']==0){
                    q.push(i);
                }
            }
        }
        
        if (alphabets != result.size()){
            return "";
        }
        
        return result;
        
    }
};