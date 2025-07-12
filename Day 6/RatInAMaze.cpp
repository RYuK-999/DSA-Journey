class Solution {
  public:
    
    void solve(int n,int x,int y,vector<vector<int>> &visited,string path,vector<string> &result,vector<vector<int>> &maze){
        
        if (x==n-1 && y==n-1){
            result.push_back(path);
            return;
        }
        
        char dir[] = {'D','L','R','U'};
        int dx[] = {1,0,0,-1};                                          //setting up directions
        int dy[] = {0,-1,1,0};                                               
        
        for (int i=0;i<4;i++){
            int nx = x+dx[i];
            int ny = y+dy[i];                                                                            //if visited marking it as 1
            if (nx>=0 && ny>=0 && nx<n && ny<n && visited[nx][ny]==0 && maze[nx][ny]==1){
                visited[nx][ny] = 1;
                solve(n,nx,ny,visited,path+dir[i],result,maze);
                visited[nx][ny] = 0;                                                                  // while backtrcking making the cell 0 again cause its available 
            }
        }
    }
    
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        
        int n = maze.size();
        
        vector<string> result;
        
        vector<vector<int>> visited(n,vector<int>(n,0));
        
        if (maze[0][0]==0 || maze[n-1][n-1]==0){
            return result;
        }
        
        visited[0][0] = 1;
        solve(n,0,0,visited,"",result,maze);
        
        return result;
    }
};