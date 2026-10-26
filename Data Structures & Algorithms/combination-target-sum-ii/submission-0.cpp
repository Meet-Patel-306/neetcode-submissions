class Solution {
   public:
    vector<int> path;
    vector<vector<int>> ans;
    void solve(vector<int>& nums, int target, int i) {
        if (target == 0) {
            ans.push_back(path);
            return;
        }
        for (int j = i; j < nums.size(); j++) {
            if (j > i && nums[j] == nums[j-1]) continue;
            if (nums[j] > target) continue;
            path.push_back(nums[j]);
            solve(nums, target - nums[j], j+1);
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        solve(nums,target,0);
        return ans;
    }
};
