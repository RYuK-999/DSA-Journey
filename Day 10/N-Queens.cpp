class Solution {
public:
    bool isSafe(vector<string> &board,int row,int col,int n){
        for (int i=0;i<col;i++){
            if (board[row][i] != '.'){
                return false;
            }
        }

        for (int i=row,j=col; i>=0 && j>=0; i--,j--){
            if (board[i][j] != '.'){
                return false;
            }
        }

        for (int i=row,j=col; i<n && j>=0; i++,j--){
            if (board[i][j] != '.'){
                return false;
            }
        }

        return true;
    }

    void helper(vector<string> &board,int col,int n,vector<vector<string>>&result){
        if (col==n){
            result.push_back(board);
            return;
        }

        for (int i=0;i<n;i++){
            if (isSafe(board,i,col,n)){
                board[i][col] = 'Q';

                helper(board,col+1,n,result);

                board[i][col] = '.';
            }
        }
    } 

    vector<vector<string>> solveNQueens(int n) {

        vector<string> board(n, string(n,'.'));
        vector<vector<string>> result;
        helper(board,0,n,result);

        return result;
    }
};