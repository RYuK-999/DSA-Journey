class Solution {
public:

    bool helper(vector<vector<char>> &board,int row, int col, int &rows, int &cols,vector<vector<int>> &visited,string &word,int element){

        if (element==word.size()){
            return true;
        }

        if ((row+1 < rows) && board[row+1][col] == word[element] && visited[row+1][col]!=1){      //Checking lower box
            visited[row+1][col] = 1;
                                       
            if (helper(board,row+1,col,rows,cols,visited,word,element+1)){
                return true;
            }

            visited[row+1][col] = 0;

        }

        if ((row-1 >= 0) && board[row-1][col] == word[element] && visited[row-1][col]!=1){      //Checking upper box
            visited[row-1][col] = 1;

            if (helper(board,row-1,col,rows,cols,visited,word,element+1)){
                return true;
            }

            visited[row-1][col] = 0;
        }

        if ((col+1 < cols) && board[row][col+1] == word[element] && visited[row][col+1]!=1){     //Checking right box
            visited[row][col+1] = 1;

            if (helper(board,row,col+1,rows,cols,visited,word,element+1)){
                return true;
            }

            visited[row][col+1] = 0;
            
        }

        if ((col-1 >= 0) && board[row][col-1] == word[element] && visited[row][col-1]!=1){      //Checking left box
            visited[row][col-1] = 1;

            if (helper(board,row,col-1,rows,cols,visited,word,element+1)){
                return true;
            }

            visited[row][col-1] = 0;
            
        }

        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();
        int element = 0;

        vector<vector<int>> visited(rows, vector<int>(cols, 0));

        for (int i=0;i<rows;i++){
            for (int j=0;j<cols;j++){
                if (word[element]==board[i][j]){
                    visited[i][j] = 1;

                    if (helper(board,i,j,rows,cols,visited,word,element+1)){
                        return true;
                    };

                    visited[i][j] = 0;
                }
            }
        }

        return false;

    }
};

//Cleaner version

class Solution {
public:
    bool helper(vector<vector<char>>& board, string& word,
                vector<vector<int>>& visited,
                int row, int col, int element) {
        
        if (element == word.size()) {
            return true;
        }

        int rows = board.size();
        int cols = board[0].size();

        if (row < 0 || row >= rows || col < 0 || col >= cols) {
            return false;
        }

        if (visited[row][col] == 1) {
            return false;
        }

        if (board[row][col] != word[element]) {
            return false;
        }

        visited[row][col] = 1;

        if (helper(board, word, visited, row + 1, col, element + 1) ||
            helper(board, word, visited, row - 1, col, element + 1) ||
            helper(board, word, visited, row, col + 1, element + 1) ||
            helper(board, word, visited, row, col - 1, element + 1)) {
            return true;
        }

        visited[row][col] = 0;

        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();

        vector<vector<int>> visited(rows, vector<int>(cols, 0));

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (helper(board, word, visited, i, j, 0)) {
                    return true;
                }
            }
        }

        return false;
    }
};


/*
In the messy method, we first stand on a cell that is already matched. Then we manually check all four directions one by one. For each direction, we check: is that neighbor inside the board, is it not visited, and does it match the next character of the word? Only after all these checks pass, we move to that neighbor. So this method is like: check first, then move.

In the cleaner method, we do the opposite. We move to a cell first by calling the helper on that position. Then inside the helper, we check whether that cell is valid or not. The helper checks if the cell is outside the board, already visited, or does not match the current character. If any of these are wrong, it returns false. If the cell is correct, then we mark it visited and again move in all four directions for the next character. So this method is like: move first, then check.
*/