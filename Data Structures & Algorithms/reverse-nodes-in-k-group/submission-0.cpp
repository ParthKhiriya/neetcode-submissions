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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        int count = 0;
        while(temp != nullptr) {
            temp = temp->next;
            count++;
        }

        ListNode* dummy = new ListNode (0, head);
        ListNode* prevGroupTail = dummy;
        temp = head;

        while(count >= k) {
            ListNode* groupHead = temp;
            ListNode* prev = nullptr;

            for(int i=0; i<k; i++) {
                ListNode* front = temp->next;
                temp->next = prev;
                prev = temp;
                temp = front;
            }

            prevGroupTail->next = prev;
            groupHead->next = temp;
            prevGroupTail = groupHead;
            count -= k;
        }

        ListNode* newHead = dummy->next;
        delete dummy;
        return newHead;
    }
};
