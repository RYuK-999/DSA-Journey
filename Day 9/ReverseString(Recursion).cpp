class Solution {
public:
    void reversing(vector<char> &s,int left,int right){
        if (left>=right){
            return;
        }

        swap(s[left],s[right]);
        left++;
        right--;

        return reversing(s,left,right);
    }

    void reverseString(vector<char>& s) {
        int left = 0;
        int right = s.size()-1;

        reversing(s,left,right);

        for (int i=0;i<=s.size()-1;i++){
            cout << s[i] << " ";
        }
    }
};

/*
Visual timeline (your "hello" example):

Start: ["h","e","l","l","o"]
Push Frame A: reversing(left=0,right=4)
swap indices 0 and 4 → array becomes ["o","e","l","l","h"]
call reversing(1,3) (push Frame B)
Push Frame B: reversing(left=1,right=3)
swap indices 1 and 3 → array becomes ["o","l","l","e","h"]
call reversing(2,2) (push Frame C)
Push Frame C: reversing(left=2,right=2)
base case true → return immediately (pop Frame C)
Pop Frame B (nothing to do after return) → return (pop Frame B)
Pop Frame A (nothing to do after return) → return (pop Frame A)
Back in reverseString, continue (e.g., print or return)

Important: the array progressed on the way down; the way up just removes frames. No extra swaps occur during unwinding.
*/




//Two pointer method (Most efficient)
class Solution{
    public:
        void reverseString(vector<char> &s){
            int left = 0;
            int right = s.size()-1;

            while (left<right){
                swap(s[left],s[right]);
                left++;
                right--;
            }
        }
};