class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> um;
        vector<int> ans;
        for(int i:nums) um[i]++;
        priority_queue<pair<int,int>> pq;
        for(auto [i,j]: um) pq.push({j,i});
        while(k--){
            auto top = pq.top();
            pq.pop();
            ans.push_back(top.second);
        }
        return ans;
    }
};
