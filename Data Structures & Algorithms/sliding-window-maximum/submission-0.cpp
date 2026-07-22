class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<int> pq;
        unordered_map<int,int> del;
        int l = 0;
        int n = nums.size();
        vector<int> ans;
        for(int r = 0; r<n;r++){
            pq.push(nums[r]);
            if((r-l+1) > k){
                del[nums[l]]++;
                l++;
            }
            while (!pq.empty() && del[pq.top()] > 0) {
                del[pq.top()]--;
                pq.pop();
            }
            if((r-l+1)==k){
                ans.push_back(pq.top());
            }
        }
        return ans;
    }
};
