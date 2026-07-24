class Solution {
public:
    void dfs(vector<vector<char>>& board,vector<vector<int>>& vis,int n,int m,int i,int j){
        if(i<0 || i>=n || j<0 || j>=m || board[i][j] == 'X' || vis[i][j]) return;
        vis[i][j] = 1;
        vector<vector<int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};
        for(auto d:dir){
            int x = i + d[0];
            int y = j + d[1];
            dfs(board,vis,n,m,x,y);
        }
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i = 0;i<m;i++){
            dfs(board,vis,n,m,0,i);
            dfs(board,vis,n,m,n-1,i);
        }
        for(int i = 0;i<n;i++){
            dfs(board,vis,n,m,i,0);
            dfs(board,vis,n,m,i,m-1);
        }
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(board[i][j] == 'O' && !vis[i][j]) board[i][j] = 'X';
            }
        }
    }
};
