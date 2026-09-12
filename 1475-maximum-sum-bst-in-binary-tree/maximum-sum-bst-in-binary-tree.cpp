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
class Box {
public:
    bool BST;
    int sum;
    int mini;
    int maxi;
    Box(){
        BST = true;
        sum = 0;
        mini = INT_MAX;
        maxi = INT_MIN;
    }
};
class Solution {
public:
    Box* find(TreeNode* root, int &sumi){
        if(!root){
            return new Box();
        }
        Box* leftHead = find(root->left, sumi);
        Box* rightHead = find(root->right, sumi);
        if(leftHead->BST && rightHead->BST && (leftHead->maxi<root->val) && (rightHead->mini>root->val)){
            Box* head = new Box();
            head->sum += leftHead->sum + rightHead->sum + root->val;
            head->mini = min(root->val,leftHead->mini);
            head->maxi = max(root->val,rightHead->maxi);
            sumi = max(sumi,head->sum);
            return head;
        }
        else{
            leftHead->BST = false;
            return leftHead;
        }
    }
    int maxSumBST(TreeNode* root) {
        int sumi = 0;
        find(root,sumi);
        return sumi;
    }
};