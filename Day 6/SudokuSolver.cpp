class Solution {
  public:
  
    bool isSafe(vector<vector<int>> &mat,int row,int col,int num){
        for (int i=0;i<9;i++){
            if (mat[row][i]==num){                                               //Checking the row if the num is unique or not
                return false;
            }
        }
        for (int j=0;j<9;j++){
            if (mat[j][col]==num){                                             //Checking the column if num is unique or not
                return false;
            }
        }
        int startRow = 3*(row/3);                                              //Finding the starting row of the respective grid of the num
        int startCol = 3*(col/3);                                              //Finding the starting col of the respective grid of the num
        for (int i=startRow;i<3+startRow;i++){
            for (int j=startCol;j<3+startCol;j++){
                if (mat[i][j]==num){                                            //Checking if the small grid if num is unique or not
                    return false;
                }
            }
        }
        return true;
    }
    
    bool solve(vector<vector<int>> &mat){
        for (int i=0;i<9;i++){
            for (int j=0;j<9;j++){
                if (mat[i][j]==0){
                    for (int num=1;num<=9;num++){                   //Checking all nums from 1 to 9 by filling step by step
                        if (isSafe(mat,i,j,num)){
                            mat[i][j]=num;
                            
                            if (solve(mat)){
                                return true;
                            }
                            mat[i][j]=0;                            
                        }
                    }
                    return false;                               //If none of the num fits we backtrack
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<int>> &mat) {
        solve(mat);
    }
};