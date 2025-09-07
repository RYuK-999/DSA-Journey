//Efficient code by having a memory for the code
class Solution {
public:
    unordered_map<int,int> memory;
    
    int fib(int n) {
        if (n==0){
            return 0;
        }
        else if (n==1){
            return 1;
        }

        

        if (memory.find(n)!=memory.end()){
            return memory[n];
        }
        else{
            memory[n]=fib(n-1)+fib(n-2);
            return memory[n];
        }
    }
};

/*
memory is a member variable, so it persists across recursive calls.
When you compute fib(n), you first check memory.
If the result exists, you return it instantly.
If not, you compute it once, store it, and never recompute it again.
*/

//Another efficient code much more efficient than the memory concept(Bottom up approach)
class Solution{
    public:
    int fib(int n){

        if (n==0 || n==1){
            return n;
        }

        int prev2 = 0;
        int prev1 = 1;

        for (int i=2;i<=n;i++){
            int curr = prev1+prev2;
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
};

/*
in this method we are not calculating fibonaacci earlier we are just building it step by step from 0,1
then by doing this step by step we will go upto the number that we want.
(Best Method FR )
*/


//Not efficient
class Solution {
public:
    int fib(int n) {
        if (n==0){
            return 0;
        }
        else if (n==1){
            return 1;
        }

        return fib(n-1) + fib(n-2);
    }
};