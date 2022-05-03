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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode * bk = head;
        while (--k > 0) {
            bk = bk->next;
        }
        ListNode * cur = bk;
        ListNode * ek = head;
        while (cur->next) {
            cur = cur->next;
            ek = ek->next;
        }
        swap(bk->val, ek->val);
        return head;
    }
};

