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
    int goodNodes(TreeNode* root) {
        if(!root) return 0;
        queue<pair<TreeNode*,int>> q;
        q.push({root,root->val});
        int ans = 0;
        int maxa = root->val;
        while(!q.empty() && root){
            auto [top,maxval] = q.front();
            q.pop();
            if(top->val >= maxval) ans++;
            int newmax = max(maxval,top->val);
            if(top->left) q.push({top->left,newmax});
            if(top->right) q.push({top->right,newmax});
        }
        return ans;
    }
};
