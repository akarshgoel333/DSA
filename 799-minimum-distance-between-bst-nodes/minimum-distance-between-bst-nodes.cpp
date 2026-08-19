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
    void find(TreeNode* root, int &prev, int &ans){
        if(!root || ans==1) return;
        find(root->left,prev,ans);
        ans = min(ans,root->val - prev);
        prev = root->val;
        find(root->right,prev,ans);

    }
    int minDiffInBST(TreeNode* root) {
        int prev = -1e7;
        int ans = INT_MAX;
        find(root,prev,ans);
        return ans;
    }
};