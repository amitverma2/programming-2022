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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (!l1 && !l2) return 0;
        int carry = 0;
        ListNode * result = 0;
        ListNode * l3 = result;
        while (l1 || l2) {
            int sum = carry;
            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            }
            carry = sum / 10;
            sum %= 10;
            if (!l3) {
                l3 = new ListNode(sum);
                result = l3;
            } else {
                ListNode * next = new ListNode(sum);
                l3->next = next;
                l3 = next;
            }
        }
        if (carry) {
            ListNode * last = new ListNode(carry);
            l3->next = last;
            l3 = last;
        }
        return result;
    }
};

