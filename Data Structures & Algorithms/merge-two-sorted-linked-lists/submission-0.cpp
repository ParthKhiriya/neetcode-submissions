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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* temp1 = list1;
        ListNode* temp2 = list2;

        if(list1 == NULL) return list2;
        if(list2 == NULL) return list1;

        ListNode* head = NULL;
        ListNode* tail = NULL;
        if(temp1->val <= temp2->val) {
            head = new ListNode(temp1->val);
            tail = head;
            temp1 = temp1->next;
        } else {
            head = new ListNode(temp2->val);
            tail = head;
            temp2 = temp2->next;
        }

        while(temp1 != NULL && temp2 != NULL) {
            if(temp1->val <= temp2->val) {
                ListNode* newNode = new ListNode(temp1->val);
                tail->next = newNode;
                tail = tail->next;
                temp1 = temp1->next;
            } else {
                ListNode* newNode = new ListNode(temp2->val);
                tail->next = newNode;
                tail = tail->next;
                temp2 = temp2->next;
            }
        }

        while(temp1 != NULL) {
            ListNode* newNode = new ListNode(temp1->val);
            temp1 = temp1->next;
            tail->next = newNode;
            tail = tail->next;
        }

        while(temp2 != NULL) {
            ListNode* newNode = new ListNode(temp2->val);
            temp2 = temp2->next;
            tail->next = newNode;
            tail = tail->next;
        }

        return head;
    }
};
