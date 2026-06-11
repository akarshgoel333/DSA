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
    ListNode* rotateRight(ListNode* head, int k) {
        if((!head) || (!head->next)) return head;
        ListNode* temp = head;
        int cnt=0;
        while(temp->next){
            cnt++;
            temp = temp->next;
        }
        cnt++;
        k %= cnt;
        ListNode* last = head;
        k = cnt-k;
        while(k>1){
            last = last->next;
            k--;
        }
        temp->next = head;
        head = last->next;
        last->next = nullptr;
        return head;
    }
};