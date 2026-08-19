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
    void find(TreeNode* root, int &k, int &ans){
        if(!root || ans!=-1) return;
        find(root->left,k,ans);
        if(k<0) return; 
        k--;
        if(k==0) ans = root->val;
        find(root->right,k,ans);

    }
    int kthSmallest(TreeNode* root, int k) {
        int ans = -1;
        find(root,k,ans);
        return ans;
    }
};