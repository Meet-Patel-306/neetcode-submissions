class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> nums;
        for(int i:nums1) nums.push_back(i);
        for(int i:nums2) nums.push_back(i);
        sort(nums.begin(),nums.end());
        int n = nums.size();
        if(n%2!=0){
            return nums[(n-1)/2];
        }
        // cout<<nums[n/2]<<" "<<nums[n/2-1];
        return (float)(nums[n/2]+nums[n/2-1])/2;
    }
};
