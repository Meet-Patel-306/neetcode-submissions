class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        for(auto i:points){
            int x = i[0],y = i[1];
            int dist = x*x+y*y;
            pq.push({dist,{x,y}});
        }
        while(k){
            k--;
            auto top = pq.top();
            pq.pop();
            ans.push_back({top.second.first,top.second.second});
        }
        return ans;
    }
};
