class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> need;
        unordered_map<char,int> win;
        for(char c:t) need[c]++;
        int l = 0;
        int len = need.size();
        int anslen = INT_MAX;
        int ansleft = 0;
        int charfind = 0;
        for(int r = 0;r<s.length();r++){
            win[s[r]]++;
            if(need.find(s[r]) != need.end() && need[s[r]] == win[s[r]]){
                charfind++;
            }
            while(charfind == len){
                if((r-l+1)<anslen){
                    anslen = r-l+1;
                    ansleft = l;
                }
                char c = s[l];
                win[s[l]]--;
                l++;
                if(need.find(c) != need.end() && need[c] > win[c]){
                    charfind--;
                }
            }
        }
        if(anslen == INT_MAX) return "";
        return s.substr(ansleft, anslen);
    }
};
