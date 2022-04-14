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
    void addDigitRecursive(ListNode * l1d, ListNode * l2d, ListNode * cur, int carry) {
        if (!l1d && !l2d) {
            // Nothing more to add, just check if we a final carry to do
            if (carry) {
                cur->next = new ListNode(carry);
            }
            return;
        }
        int sum = carry;
        if (l1d) {
            sum += l1d->val;
            l1d = l1d->next;
        }
        if (l2d) {
            sum += l2d->val;
            l2d = l2d->next;
        }
        cur->next = new ListNode(sum % 10);
        addDigitRecursive(l1d, l2d, cur->next, sum / 10);
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode * begin = new ListNode(0);
        addDigitRecursive(l1, l2, begin, 0);
        return begin->next;
    }
             
};

