class Solution {
   public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> v;
        for (int i = 0; i < speed.size(); i++) 
            v.push_back({position[i], speed[i]});
        sort(v.rbegin(), v.rend());
        double time = (double)(target - v[0].first) / v[0].second;
        int ans = 1;
        for (int i = 1; i < v.size(); i++) {
            double curr = (double)(target - v[i].first) / v[i].second;
            if (curr>time) {
                time = curr;
                ans++;
            }
        }
        return ans;
    }
};
