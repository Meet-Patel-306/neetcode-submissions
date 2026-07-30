class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        int left = 0;
        int len = 0;
        for(int i = 0;i<n;i++){
            for(int j = i;j<n;j++){
                string str = s.substr(i, j-i+1);
                string temp = str;
                reverse(temp.begin(),temp.end());
                if(temp == str){
                    if((j-i+1)>len){
                        len = j-i+1;
                        left = i;
                    }
                }
            }
        }
        return s.substr(left, len);
    }
};
