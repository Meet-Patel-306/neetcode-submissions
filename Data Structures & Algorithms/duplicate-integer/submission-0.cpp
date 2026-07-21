class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int,int> um;
        for(int i:nums) um[i]++;
        for(int i:nums) 
            if(um[i]>1) return true;
        return false;
    }
};