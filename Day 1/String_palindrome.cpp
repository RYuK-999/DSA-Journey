class Solution {
  public:
    // Function to check if a string is a palindrome.
    bool isPalindrome(string& s) {
        int size = s.size();
        
        for (int i=0;i<size;i++){
            if (s[i]!=s[size-1]){
                return 0;
            }
            else{
                size--;
            }
        }
        return 1;
    }
};