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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy_head;
        dummy_head.next = head;
        ListNode *cur = &dummy_head;
        ListNode *nth = 0;
        while (n-- > 0) {
            cur = cur->next;
        }
        nth = &dummy_head;
        while (cur->next) {
            cur = cur->next;
            nth = nth->next;
        }
        // we need to remove the one after nth node
        ListNode * removed = nth->next;
        nth->next = removed->next;
        removed->next = 0;
        return dummy_head.next;
    }
};

