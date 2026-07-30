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
        if(root==NULL || root==p || root==q) return root;
        TreeNode* lef = lowestCommonAncestor(root->left,p,q);
        TreeNode* rig = lowestCommonAncestor(root->right,p,q);
        if(lef == NULL) return rig;
        else if(rig == NULL) return lef;
        else return root;
    }
};