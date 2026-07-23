class Solution {
   public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;
        int num = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2)
                    q.push({i, j});
                else if (grid[i][j] == 1)
                    num++;
            }
        }
        int ans = 0;
        while (!q.empty() && num>0) {
            int size = q.size();
            vector<vector<int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
            while (size--) {
                auto top = q.front();
                int r = top.first;
                int c = top.second;
                q.pop();
                for (auto i : dir) {
                    int x = r + i[0];
                    int y = c + i[1];
                    if (x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == 1) {
                        grid[x][y] = 2;
                        num--;
                        q.push({x, y});
                    }
                }
            }
            ans++;
        }
        return num == 0 ? ans:-1;
    }
};
