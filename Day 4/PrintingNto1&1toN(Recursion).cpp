// Printing from 1 to N

class Solution {
  public:
    void printTillN(int n) {
        
        if (n==1){
            cout << "1 ";
            return;
        }
        
        printTillN(n-1);
        
        cout << n <<" ";
        
    }
};

// Printing from N to 1

class Solution {
  public:
    void printNos(int N) {
        
        if (N==1){
            cout << "1";
            return;
        }
        
        cout << N << " ";
        
        printNos(N-1);
        
    }
};