class Solution {
public:
    int solve(vector<vector<int>>& dp, vector<int>& nums, int i, int prev) {

        if (i == nums.size())
            return 0;

        // prev + 1 because prev can be -1
        if (dp[i][prev + 1] != -1)
            return dp[i][prev + 1];

        // Don't take
        int nottaken = solve(dp, nums, i + 1, prev);

        // Take
        int taken = 0;

        if (prev == -1 || nums[prev] < nums[i]) {
            taken = 1 + solve(dp, nums, i + 1, i);
        }

        return dp[i][prev + 1] = max(taken, nottaken);
    }

    int lengthOfLIS(vector<int>& nums) {

        int n = nums.size();

        // n + 1 columns because prev can be -1
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));

        return solve(dp, nums, 0, -1);
    }
};