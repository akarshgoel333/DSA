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
    void good(TreeNode* root, bool &flag, long long &prev){
        if(!root || !flag) return;
        good(root->left,flag,prev);
        if(root->val <= prev){
            flag = false;
            return;
        }
        prev = root->val;
        good(root->right,flag,prev);
    }
    bool isValidBST(TreeNode* root) {
        bool flag = true;
        long long prev = LLONG_MIN;
        good(root,flag,prev);
        return flag;
    }
};