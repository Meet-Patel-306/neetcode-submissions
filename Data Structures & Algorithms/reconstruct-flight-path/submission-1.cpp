class Solution {
public:
    void dfs(string node,unordered_map<string,vector<string>>& um,vector<string>& ans){
        while(!um[node].empty()){
            string it = um[node].back();
            um[node].pop_back();
            dfs(it,um,ans);
        }
        ans.push_back(node);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string,vector<string>> um;
        for(auto &it:tickets){
            um[it[0]].push_back(it[1]);
        }
        for(auto &[src,dest]:um){
            sort(dest.rbegin(), dest.rend());
        }
        vector<string> ans;
        dfs("JFK",um,ans);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
