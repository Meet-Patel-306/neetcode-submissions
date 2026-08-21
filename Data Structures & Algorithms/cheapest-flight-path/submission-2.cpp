class Solution {
   public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto i:flights){
            adj[i[0]].push_back({i[1],i[2]});
        }
        vector<int> dis(n, INT_MAX);
        // priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,
        //                greater<pair<int, pair<int, int>>>>
        //     pq;
        queue<pair<int, pair<int, int>>> pq;
        pq.push({0,{src,0}});
        dis[src] = 0;
        while(!pq.empty()){
            auto top = pq.front();
            pq.pop();
            int w = top.first;
            int u = top.second.first;
            int step = top.second.second;
            // cout<<"loop run"<<endl;
            if(step > k) continue;
            for(auto i:adj[u]){
                int v = i.first;
                int price = i.second;
                if(step<=k && w+price<dis[v]){
                    // cout<<"loop run 2"<<endl;
                    dis[v] = w+price;
                    pq.push({dis[v],{v,step+1}});
                }
            }
        }
        // for(int i:dis) cout<<i<<" ";
        return dis[dst] == INT_MAX ? -1 : dis[dst];
    }
};
