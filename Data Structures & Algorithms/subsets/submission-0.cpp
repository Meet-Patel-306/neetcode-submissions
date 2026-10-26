class Solution {
public:
    vector<int> path;
    vector<vector<int>> ans;
    void solve(vector<int>& nums,int i){
        ans.push_back(path);
        for(int j = i;j<nums.size();j++){
            path.push_back(nums[j]);
            solve(nums,j+1);
            path.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        solve(nums,0);
        return ans;
    }
};
