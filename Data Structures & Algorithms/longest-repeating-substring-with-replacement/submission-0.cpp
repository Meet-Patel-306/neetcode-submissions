class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0;
        int n = s.length();
        unordered_map<char,int> um;
        int maxcnt = 0;
        int ans = 0;
        for(int r = 0;r<n;r++){
            um[s[r]]++;
            maxcnt = max(maxcnt,um[s[r]]);
            while((r-l+1)-maxcnt>k){
                um[s[l]]--;
                l++;
            }
            ans = max(ans,r-l+1);
        }
        return ans;
    }
};
