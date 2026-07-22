class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        int r;
        unordered_set<char> us;
        int ans = 0;
        for(r = 0;r<s.length();r++){
            while(us.find(s[r]) != us.end()){
                us.erase(s[l]);
                l++;
            }
            ans = max(ans,(r-l+1));
            us.insert(s[r]);
        }
        return ans;
    }
};
