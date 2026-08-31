/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int first = -1, last = -1;
        ListNode* curr = head->next;
        ListNode* prev = head;
        int i = 1;
        int mini = INT_MAX;
        while(curr->next){
            bool flag = (curr->val < prev->val && curr->val < curr->next->val) || (curr->val > prev->val && curr->val > curr->next->val);
            if(flag){
                if(first==-1) first=i;
                else mini = min(mini,i-last);
                last = i;
            }
            i++;
            prev = curr;
            curr = curr->next;
        }
        if(first==last) return {-1,-1};
        int maxi = last-first;
        return {mini,maxi};
    }
};