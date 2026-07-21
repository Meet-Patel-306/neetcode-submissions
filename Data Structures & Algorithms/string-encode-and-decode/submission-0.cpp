class Solution {
public:

    string encode(vector<string>& strs) {
        string en_s = "";
        for(string s:strs){
            en_s+=s;
            en_s+=';';
        }
        return en_s;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        string str = "";
        for(char c:s){
            if(c == ';'){
                ans.push_back(str);
                str = "";
                continue;
            }
            str+=c;
        } 
        return ans;
    }
};
