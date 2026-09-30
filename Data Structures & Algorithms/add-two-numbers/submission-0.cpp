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
        int carry = 0;
        int val = 0;
        ListNode *dummy = new ListNode(0);
        ListNode *temp = dummy;

        while (l1 && l2) {

            int summ = 0;

            if (carry) {
                summ = l1->val + l2->val + 1;
                carry = 0;
            } else {
                summ = l1->val + l2->val;
            }

            val = summ % 10;          // fix 1: always recompute val, not just when >9
            if (summ > 9) {
                carry = 1;
            }

            ListNode *newNode = new ListNode(val);
            temp->next = newNode;
            temp = temp->next;
            l1 = l1->next;
            l2 = l2->next;
        }

        // fix 3/4: propagate any pending carry into the remaining longer list
        ListNode *rest = l1 ? l1 : l2;
        while (rest) {
            int summ = rest->val + carry;
            val = summ % 10;
            carry = summ > 9 ? 1 : 0;

            temp->next = new ListNode(val);
            temp = temp->next;
            rest = rest->next;
        }

        // fix 2: leftover carry after everything else
        if (carry) {
            temp->next = new ListNode(carry);
        }

        return dummy->next;
    }
};