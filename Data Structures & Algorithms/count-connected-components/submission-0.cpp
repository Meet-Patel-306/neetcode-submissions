class Solution {
public:
    void dfs(vector<vector<int>>& adj,vector<int>& vis,int i){
        vis[i] = 1;
        for(auto node:adj[i]){
            if(!vis[node]) dfs(adj,vis,node);
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto i :edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        vector<int> vis(n,0);
        int ans = 0;
        for(int i = 0;i<n;i++){
            if(!vis[i]){
                ans++;
                dfs(adj,vis,i);
            }
        }
        return ans;
    }
};
