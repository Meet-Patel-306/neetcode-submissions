class DSU {
   public:
    vector<int> rank, parent;
    DSU(int n) {
        rank.resize(n);
        parent.resize(n);
        for (int i = 0; i < n; i++) {
            rank[i] = 1;
            parent[i] = i;
        }
    }
    int find(int i) { return parent[i] == i ? i : (parent[i] = find(parent[i])); }
    void unit(int i, int j) {
        int s1 = find(i);
        int s2 = find(j);
        if (s1 != s2) {
            if (rank[s1] > rank[s2])
                parent[s2] = s1;
            else if (rank[s1] < rank[s2])
                parent[s1] = s2;
            else {
                parent[s2] = s1;
                rank[s1]++;
            }
        }
    }
};
class Solution {
   public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<pair<int, pair<int, int>>> adj;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int dis = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                adj.push_back({i, {j, dis}});
                adj.push_back({j, {i, dis}});
            }
        }
        sort(adj.begin(), adj.end(),
             [](auto& a, auto& b) { return a.second.second < b.second.second; });
        int cost = 0;
        int count = 0;
        DSU dsu(n);
        for (int i = 0; i < adj.size(); i++) {
            int u = adj[i].first, v = adj[i].second.first, w = adj[i].second.second;
            if (dsu.find(u) != dsu.find(v)) {
                dsu.unit(u, v);
                cost += w;
                count++;
                if(count == n-1) break;
            }
        }
        return cost;
    }
};
