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
        int crt = 0;
        int i = 1;
        int mini = INT_MAX;
        while(curr->next){
            if((curr->val < prev->val && curr->val < curr->next->val) || (curr->val > prev->val && curr->val > curr->next->val)){
                crt++;
                if(first==-1) first=i;
                if(last!=-1 && i-last<mini) mini = i-last;
                last = i;
            }
            i++;
            prev = curr;
            curr = curr->next;
        }
        if(crt<2) return {-1,-1};
        int maxi = last-first;
        return {mini,maxi};
    }
};