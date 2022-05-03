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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode dummy_head;
        dummy_head.next = head;
        
        ListNode *half = &dummy_head;
        ListNode *cur = head->next;
        
        while (cur) {
            half = half->next;
            cur = cur->next;
            if (cur) cur = cur->next;
        }
        ListNode * removed = half->next;
        half->next = removed->next;
        removed->next = nullptr;
        
        return dummy_head.next;
    }
};

