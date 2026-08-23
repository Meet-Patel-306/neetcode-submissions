/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    void makearr(TreeNode* root,vector<int>& nums){
        if(!root) return;
        nums.push_back(root->val);
        makearr(root->left,nums);
        makearr(root->right,nums);
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> nums;
        makearr(root,nums);
        sort(nums.begin(), nums.end());
        return nums[k-1];
    }
};

