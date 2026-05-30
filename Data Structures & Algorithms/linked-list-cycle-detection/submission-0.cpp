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
    bool hasCycle(ListNode* head) {
        unordered_map<ListNode*, int> mpp;
        ListNode* temp = head;

        while(temp != nullptr) {
            mpp[temp]++;
            if(mpp[temp] > 1) return true;
            temp = temp->next; 
        }

        return false;
    }
};
