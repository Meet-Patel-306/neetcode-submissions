class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int maxprod = nums[0];
        int minprod = nums[0];
        int ans = nums[0];
        for(int i = 1;i<n;i++){
            int x = nums[i];
            if(x<0) swap(minprod,maxprod);
            maxprod = max(x,maxprod*x);
            minprod = min(x,minprod*x);
            ans = max(ans,maxprod);
        }
        return ans;
    }
};
