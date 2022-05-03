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
        ListNode *cur = head;
        ListNode *nth = 0;
        while (n-- > 0) {
            cur = cur->next;
        }
        if (cur == 0) {
            // head needs to be removed
            ListNode * new_head = head->next;
            head->next = 0;
            return new_head;
        }
        nth = head;
        while (cur->next) {
            cur = cur->next;
            nth = nth->next;
        }
        // we need to remove the one after nth node
        ListNode * removed = nth->next;
        nth->next = removed->next;
        removed->next = 0;
        return head;
    }
};

