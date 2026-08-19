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
    TreeNode* form(vector<int>&preo, int mini, int maxi, int &idx, int n){
        if(idx>=n) return nullptr;
        if(preo[idx]>=maxi || preo[idx]<=mini) return nullptr;
        TreeNode* curr = new TreeNode(preo[idx++]);
        curr->left = form(preo,mini,curr->val,idx,n);
        curr->right = form(preo,curr->val,maxi,idx,n);
        return curr;
    }
    TreeNode* bstFromPreorder(vector<int>& preo) {
        int mini = INT_MIN;
        int maxi = INT_MAX;
        int idx = 0;
        return form(preo,mini,maxi,idx,preo.size());
    }
};