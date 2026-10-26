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
            if (nums[j] > target) continue;
            path.push_back(nums[j]);
            solve(nums, target - nums[j], j);
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        solve(nums,target,0);
        return ans;
    }
};
