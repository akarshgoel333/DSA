/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return NULL;
        int a = p->val, b = q->val, c = root->val;
        if(a>b) swap(a,b);
        if(c>b) return lowestCommonAncestor(root->left,p,q);
        else if(c<a) return lowestCommonAncestor(root->right,p,q);
        else return root;
    }
};