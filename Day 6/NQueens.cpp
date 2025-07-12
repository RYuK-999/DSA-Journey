class Solution {
  public:
  
    void solve(int n,vector<int> &rowlist,vector<vector<int>> &result){
        if (n==rowlist.size()){
            vector<int> oneBased;                                       //Making the index one based
            for (r : rowlist){
                oneBased.push_back(r+1);
            }
            result.push_back(oneBased);
            return;
        }
        
        int col = rowlist.size();
        
        for (int row=0;row<n;++row){                                   //Checking different rows with this loop
            bool isSafe = true;
            
            for (int i=0;i<rowlist.size();++i){                        //Checking previously inserted queens if they create problem with
                int prow = rowlist[i];                                 //the current queen, if anyone of them create problem we go for 
                int pcol = i;                                          //next row without any delays
                
                if (prow==row){
                    isSafe = false;                                     // checking if row is same or not
                    break;
                }
                
                if (abs(prow-row)==abs(pcol-col)){                       // checking if diagonal is same or not
                    isSafe = false;
                    break;
                }
            }
            
            if (isSafe){
                rowlist.push_back(row);
                solve(n,rowlist,result);
                rowlist.pop_back();
            }
        }
    }
    
    vector<vector<int>> nQueen(int n) {
        vector<vector<int>> result;
        
        vector<int> rowlist;
        
        solve(n,rowlist,result);
        return result;
    }
};