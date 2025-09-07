class Solution {
public:
    int trailingZeroes(int n) {
        int count_zero = 0;

        while (n>0){
            n = n/5;
            count_zero += n;
        }

        return count_zero;
    }
};

/*
What’s happening conceptually

First division (n / 5) counts all numbers with at least one 5.

Second division (shrink n and divide again by 5) is a clever shortcut for /25.

Because when you do n = n/5, you’re essentially saying:
“okay, I’ve already stripped one 5 out of every multiple-of-5. Now, among those, who still has another 5 left inside?”

So the “shrinking” version is just the same as /25, /125, /625, …, but written as a loop.




And one more thing normally if we want to find trailing zeroes we check how many times 5 is coming in the
number cause 5 only will bring zero at the end
-> in other words no_of_fives = no_of_trailing_zeroes

*/