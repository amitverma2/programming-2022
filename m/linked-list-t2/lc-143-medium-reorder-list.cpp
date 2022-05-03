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
    void reorderList(ListNode* head) {
        deque<ListNode*> dq;
        ListNode * cur = head;
        while (cur) {
            dq.push_front(cur);
            cur = cur->next;
        }
        while (dq.size() > 2) {
            ListNode * front = dq.front();
            ListNode * back = dq.back();
            dq.pop_front();
            dq.pop_back();
            ListNode * newLast = dq.front();
            newLast->next = nullptr;
            ListNode * newHead = dq.back();
            
            back->next = front;
            front->next = newHead;
        }
    }
};

