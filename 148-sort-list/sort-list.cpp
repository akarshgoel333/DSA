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
    ListNode* solve(ListNode* l1, ListNode* l2){
        ListNode *newhead = new ListNode(0);
        ListNode *tail = newhead;

        while(l1 && l2){
            if(l1->val <= l2->val){
                tail->next = l1;
                l1 = l1->next;
            }
            else{
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }
        if(l1) tail->next = l1;
        if(l2) tail->next = l2;
        return newhead->next;
    }
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode *start = head;
        ListNode *fast = head;
        ListNode *temp = nullptr;
        while(fast && fast->next){
            temp = start;
            start = start->next;
            fast = fast->next->next;
        }
        temp->next = nullptr;
        ListNode *l1 = sortList(head);
        ListNode *l2 = sortList(start);
        return solve(l1,l2);
    }
};