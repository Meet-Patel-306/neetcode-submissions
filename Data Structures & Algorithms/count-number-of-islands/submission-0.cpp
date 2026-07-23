class Solution {
public:
    void dfs(vector<vector<char>>& grid,int n,int m,int i,int j){
        if(i<0 || i>=n || j<0 || j>=m || grid[i][j] == '0') return;
        vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
        grid[i][j] = '0';
        for(auto d:dir){
            int x = i+d[0];
            int y = j+d[1];
            dfs(grid,n,m,x,y);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans=0;
        for(int i = 0;i<n;i++){
            for(int j= 0;j<m;j++){
                if(grid[i][j] == '1'){
                    ans++;
                    dfs(grid,n,m,i,j);
                }
            }
        }
        return ans;
    }
};
