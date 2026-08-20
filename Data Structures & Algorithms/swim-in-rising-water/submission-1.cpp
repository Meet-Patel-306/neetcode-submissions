class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dis(n,vector<int>(n,INT_MAX));
        // queue<pair<int,pair<int,int>>> q;
priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> q;
        q.push({grid[0][0],{0,0}});
        dis[0][0] = grid[0][0];
        // int time = 0;
        while(!q.empty()){
            auto top = q.top();
            q.pop();
            int time = top.first;
            int i = top.second.first;
            int j = top.second.second;
            if(i == n-1 && j == n-1) return time;
            if(dis[i][j]<time) continue;
            vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
            for(auto d:dir){
                int x = i+d[0];
                int y = j+d[1];
                if(x<n && y<n && x>=0 && y>=0){
                    int newTime = max(time,grid[x][y]);
                    if(newTime<dis[x][y]){
                        dis[x][y] = newTime;
                        q.push({newTime,{x,y}});   
                    }                 
                }
            }
        }
        return -1;
    }
};
