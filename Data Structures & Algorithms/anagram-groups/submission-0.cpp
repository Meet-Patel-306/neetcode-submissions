class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> um;
        for(string s:strs){
            string temp = s;
            sort(temp.begin(),temp.end());
            um[temp].push_back(s);
        }
        vector<vector<string>> ans;
        for(auto [i,j]:um) ans.push_back(j);
        return ans;
    }
};
