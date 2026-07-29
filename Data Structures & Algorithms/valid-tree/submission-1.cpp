class Solution {
public:
    void dfs(vector<vector<int>>& adj,vector<int>& vis,int i){
        vis[i] = 1;
        for(auto node : adj[i]){
            if(!vis[node])
                dfs(adj,vis,node);
        }
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size() != n-1) return false;
        vector<vector<int>> adj(n);
        for(auto i:edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        vector<int> vis(n,0);
        dfs(adj,vis,0);
        int ans = 0;
        for(int i:vis) if(!i) return false;
        return true;
    }
};
