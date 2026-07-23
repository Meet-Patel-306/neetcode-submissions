class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int INF = 2147483647;
        queue<pair<int,int>> q;
        int n = grid.size();
        int m = grid[0].size();
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j] == 0) q.push({i,j});
            }
        }
        while(!q.empty()){
            auto top = q.front();
            int r = top.first;
            int c = top.second;
            q.pop();
            vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
            for(auto i:dir){
                int x = r+i[0];
                int y = c+i[1];
                if(x<0 || x>=n || y<0 || y>=m || grid[x][y] != INF) continue;
                grid[x][y] = 1+grid[r][c];
                q.push({x,y});
            }
        }
    }
};
