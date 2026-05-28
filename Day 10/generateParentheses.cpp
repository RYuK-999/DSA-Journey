class Solution {
public:

    void helper(vector<string> &result,int n,int openUsed, int closeUsed, string &ans){

        if (ans.size() == 2*n){
            result.push_back(ans);
            return;
        }

        if (openUsed < n){
            ans.push_back('(');
            openUsed++;

            helper(result,n,openUsed,closeUsed,ans);

            openUsed--;
            ans.pop_back();
        }

        if (closeUsed < n && closeUsed < openUsed){           // No need of "closeUsed < n" cause openUsed is less than n so automatically closeUsed is also less than n ^-^
            ans.push_back(')');
            closeUsed++;

            helper(result,n,openUsed,closeUsed,ans);

            closeUsed--;
            ans.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        int openUsed = 0;
        int closeUsed = 0;
        vector<string> result;
        string ans;

        helper(result,n,openUsed,closeUsed,ans);

        return result;
    }
};


//Same thing not much difference
class Solution {
public:
    void helper(vector<string>& result, int n, int openUsed, int closeUsed, string& ans) {
        if (ans.size() == 2 * n) {
            result.push_back(ans);
            return;
        }

        if (openUsed < n) {
            ans.push_back('(');
            helper(result, n, openUsed + 1, closeUsed, ans);
            ans.pop_back();
        }

        if (closeUsed < openUsed) {
            ans.push_back(')');
            helper(result, n, openUsed, closeUsed + 1, ans);
            ans.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string ans;

        ans.reserve(2 * n);            //Reserve give it a constant space of 2n in the start :)

        helper(result, n, 0, 0, ans);

        return result;
    }
};