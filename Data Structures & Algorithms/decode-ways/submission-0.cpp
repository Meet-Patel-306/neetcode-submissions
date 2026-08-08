class Solution {
public:
    int solve(string &s,int i,vector<int>& dp){
        if(i == s.size()) return 1;
        if(s[i] == '0') return 0;
        if(dp[i]!= -1) return dp[i];
        // one nums
        int pick = solve(s,i+1,dp);
        // two nums
        int picktwo = 0;
        if(i+1<s.length()){
            int num = (s[i]-'0')*10 + (s[i+1]-'0');
            if(num >= 10 && num<=26){
                picktwo = solve(s,i+2,dp);
            }
        }
        return dp[i] = pick+picktwo;
    }
    int numDecodings(string s) {
        int n = s.length();
        vector<int> dp(n,-1);
        return solve(s,0,dp);
    }
};
