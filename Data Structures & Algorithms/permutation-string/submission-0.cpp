class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int> um;
        for(char c:s1) um[c]++;
        int l = 0;
        int r;
        int n = s2.length();
        int m = s1.length();
        unordered_map<char,int> um2;
        for(r = 0;r<n;r++){
            if((r-l+1)>m){
                um2[s2[l]]--;
                if(um2[s2[l]] == 0) um2.erase(s2[l]);
                l++;
            }
            um2[s2[r]]++;
            if(um == um2) return true;
        }
        return false;
    }
};
