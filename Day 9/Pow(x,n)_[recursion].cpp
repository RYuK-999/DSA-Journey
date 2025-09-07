class Solution {
public:
    double helper(double x,long long int N){
        if (N==1){
            return x;
        }
        else if (N==0){
            return 1;
        }

        if (N%2==0){
            double half = helper(x,N/2);
            return half*half;
        }
        else{
            double half = helper(x,N/2);
            return x*half*half;
        }
    }

    double myPow(double x, int n) {
        
        long long int N = n;
        if (N<0){
            return 1.0/helper(x,-N);
        }
        else{
            return helper(x,N);
        }
    }
};

/*
How the whole thing works

myPow:
Promotes n to long long N.
If N < 0: flip sign, return reciprocal.
Else call helper.

helper:
Handles only positive powers.
Uses divide & conquer (O(log n)).
*/





/*  How the whole thing works

Step 1: The first call

helper(2, 5)
N = 5, not 0 or 1 → go further.
Compute half = helper(2, 5/2) = helper(2, 2) (because integer division floors 5/2 → 2).
At this point, nothing is returned yet. The program “pauses” at this line until helper(2,2) finishes.
Think of recursion like stacking plates: every function call waits for the one it called to finish before it can continue.

Step 2: Second call

helper(2, 2)
N = 2, not 0 or 1 → compute half = helper(2, 1)
Again, program “pauses” at this line until helper(2,1) finishes.

Step 3: Third call (base case)

helper(2, 1)
N = 1 → hit the base case → return x = 2.
Now the stack starts unwinding.

Step 4: Returning to helper(2,2)

half = helper(2,1) → half = 2 now.
N % 2 == 0 → even → return half * half = 2 * 2 = 4.
So helper(2,2) returns 4 to the first call.

Step 5: Returning to helper(2,5)

half = helper(2,2) → half = 4 now.
N % 2 != 0 → odd → return x * half * half = 2 * 4 * 4 = 32.

✅ Done. The result of helper(2,5) is 32.
*/