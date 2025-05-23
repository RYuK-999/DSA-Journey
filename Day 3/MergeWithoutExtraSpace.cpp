// Without Extra Space

class Solution {
  public:
    void mergeArrays(vector<int>& a, vector<int>& b) {
        int n = a.size();
        int m = b.size();
        int gap = ceil((n+m)/2.0);
        
        while (gap>0){
            int i = 0;
            int j = gap;
            
            while (j<n+m){
                int val1 = (i<n) ? a[i] : b[i-n];
                int val2 = (j<n) ? a[j] : b[j-n];
                
                if (val1>val2){
                    if (i<n && j<n){
                        swap(a[i],a[j]);
                    }
                    else if (i<n && j>=n){
                        swap(a[i],b[j-n]);
                    }
                    else{
                        swap(b[i-n],b[j-n]);
                    }
                }
                
                i++;
                j++;
            }
            
            if (gap==1){
                break;
            }
            
            gap = ceil(gap/2.0);
        }
        
    }
};


// With Extra Space

class Solution {
  public:
    void mergeArrays(vector<int>& a, vector<int>& b) {
        int first = a.size();
        int second = b.size();
        
        vector<int> big;
        
        for (int i=0;i<first;i++){
            big.push_back(a[i]);
        }
        for (int i=0;i<second;i++){
            big.push_back(b[i]);
        }
        
        sort(big.begin(),big.end());
        
        int j=0;
        for(int i=0;i<first;i++){
            a[i]=big[j];
            j++;
        }
        for (int i=0;i<second;i++){
            b[i]=big[j];
            j++;
        }
    }
};