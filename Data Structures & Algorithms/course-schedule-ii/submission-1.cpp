class Solution {
   public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for (auto i : prerequisites) {
            adj[i[1]].push_back(i[0]);
        }
        vector<int> ind(numCourses, 0);
        for (auto i : adj) {
            for (int j : i) {
                ind[j]++;
            }
        }
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (ind[i] == 0) q.push(i);
        }
        int ans = 0;
        vector<int> res;
        while (!q.empty()) {
            int top = q.front();
            q.pop();
            ans++;
            res.push_back(top);
            for (int i : adj[top]) {
                ind[i]--;
                if (ind[i] == 0) q.push(i);
            }
        }
        if(ans != numCourses) return {};
        return res;
    }
};
