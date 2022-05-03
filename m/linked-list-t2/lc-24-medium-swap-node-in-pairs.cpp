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
    ListNode* swapPairs(ListNode* head) {
        ListNode dummy_head;
        dummy_head.next = head;
        
        if (!head || !head->next) return head; // ease of work
        
        ListNode *p = &dummy_head;
        while (p->next && p->next->next) {
            ListNode *temp = p->next;
            p->next = p->next->next;
            temp->next = p->next->next;
            p->next->next = temp;
            p = temp;
        }
        return dummy_head.next;        
    }
};

