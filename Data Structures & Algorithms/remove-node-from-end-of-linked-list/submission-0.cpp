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
        ListNode* temp = head;

        int count = 0;
        while(temp != nullptr) {
            temp = temp->next;
            count++;
        }
        int target = count - n;

        if(target == 0) {
            ListNode* newHead = head->next;
            return newHead;
        }

        temp = head;

        for(int i=0; i<target-1; i++) {
            temp = temp->next;
        }
        temp->next = temp->next->next;

        return head;
    }
};
