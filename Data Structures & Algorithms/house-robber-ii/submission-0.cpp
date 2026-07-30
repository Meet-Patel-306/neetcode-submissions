class Solution {
public:
    int solve(vector<int>& nums,vector<int>& dp,int i){
        if(i == 0) return nums[0];
        if(i<0) return 0;
        if(dp[i] != -1) return dp[i];
        int pick = nums[i] + solve(nums,dp,i-2);
        int notpick = solve(nums,dp,i-1);
        return dp[i] = max(pick,notpick); 
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        vector<int> dp(n,-1);
        vector<int> dp2 = dp;
        vector<int> arr,arr2;
        for(int i = 0;i<n;i++){
            if(i != 0) arr.push_back(nums[i]);
            if(i != n-1) arr2.push_back(nums[i]);
        }
        return max(solve(arr,dp,n-2),solve(arr2,dp2,n-2));
    }
};
