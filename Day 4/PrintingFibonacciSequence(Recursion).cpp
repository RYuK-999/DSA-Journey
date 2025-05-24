class Solution {
  public:
    vector<int> fibonacciNumbers(int n) {
        if (n == 1){
            return {0};
        }
        if (n == 2){
            return {0, 1};
        }

        vector<int> fibo = fibonacciNumbers(n - 1);

        int next = fibo[fibo.size() - 1] + fibo[fibo.size() - 2];

        fibo.push_back(next);

        return fibo;
    }
};