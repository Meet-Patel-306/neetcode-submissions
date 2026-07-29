class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto i :times){
            adj[i[0]].push_back({i[1],i[2]});
        }
        vector<int> t(n+1,INT_MAX);
        t[0] = 0;
        t[k] = 0;
        queue<pair<int,int>> q;
        q.push({k,0});
        while(!q.empty()){
            auto [v,wt] = q.front();
            q.pop();
            // if(wt>t[v]) continue;
            for(auto i : adj[v]){
                int u = i.first;
                int time = i.second;
                if(wt+time<t[u]){
                    t[u] = wt+time;
                    q.push({u,t[u]});
                }
            }
        }
        int ans = 0;
        for(int i:t){
            if(i == INT_MAX) return -1;
            ans = max(ans,i);
        }
        return ans;
    }
};
