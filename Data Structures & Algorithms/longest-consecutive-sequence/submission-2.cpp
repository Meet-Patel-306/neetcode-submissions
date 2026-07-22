class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> us;
        int n = nums.size();
        if(n == 1) return 1;
        for(int i: nums) us.insert(i);
        int ans = 0;
        for(int i:nums){
            if(us.find(i-1) == us.end()){
                int cur = i;
                int len = 1;
                while(us.find(cur+1)!=us.end()){
                    len++;
                    cur++;
                }
                ans = max(ans,len);
            }
        }
        return ans;
    }
};
