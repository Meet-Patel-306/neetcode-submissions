class Solution {
public:
    int solve(string s,vector<string>& wordDict,vector<int>& dp,int i){
        if(i == s.length()) return 1;
        if(dp[i] != -1) return dp[i];
        for(int j = 0;j<wordDict.size();j++){
            int len = wordDict[j].size();
            if((i+len)<=s.length() && (s.substr(i, len) == wordDict[j])){
                if(solve(s,wordDict,dp,i+len)){
                    return dp[i] = 1;
                }
            }
        }
        return dp[i] = 0;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = wordDict.size();
        vector<int> dp(s.length(),-1);
        return solve(s,wordDict,dp,0);
    }
};
