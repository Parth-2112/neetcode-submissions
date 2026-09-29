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
        int size = 0;
        ListNode *temp = head;
        while (temp) {
            size++;
            temp = temp->next;
        }

        int rmindex = size - n;

        if (rmindex == 0) {
            return head->next;   // removing the head itself
        }

        temp = head;
        for (int i = 0; i < rmindex - 1; i++) {
            temp = temp->next;
        }
        temp->next = temp->next->next;

        return head;
    }
};
