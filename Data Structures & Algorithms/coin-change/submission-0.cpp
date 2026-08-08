class Solution {
public:
    int solve(vector<int>& coins, int amount,vector<int>& dp){
        if(amount == 0) return 0;
        if(amount < 0) return -1;
        if(dp[amount]!=-2) return dp[amount];
        int ans = INT_MAX;
        for(int c = 0;c<coins.size();c++){
            int res = solve(coins,amount-coins[c],dp);
            if(res >= 0 && res<ans){
                ans = res+1;
            }
        }
        return dp[amount] = ans == INT_MAX ? -1 : ans;
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> dp(amount+1,-2);
        return solve(coins,amount,dp);
    }
};
