class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int i = 0;i<n;i++) dp[i][i] = 1;
        int l = 0;
        int len = 1;
        for(int i = 0;i<n-1;i++){
            if(s[i] == s[i+1]){
                dp[i][i+1] = 1;
                if(len == 1){
                    l = i;
                    len = 2;
                }
            }
        }

        for(int leng = 3;leng<=n;leng++){
            for(int i = 0;i<=n-leng;i++){
                int j = i+leng-1;
                if(s[i] == s[j] && dp[i+1][j-1]){
                    dp[i][j] = 1;
                }
            }
        }
        int ans = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                if(dp[i][j]) ans++;
                // cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
            }
        }
        return ans;
    }
};
