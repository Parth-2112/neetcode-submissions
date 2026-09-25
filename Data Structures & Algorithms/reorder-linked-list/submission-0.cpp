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

        if(head->next == nullptr || head->next->next == nullptr)
            return;

        vector<ListNode*> index;
        ListNode *temp = head;
        int n=0;

        while(temp){
            index.push_back(temp);
            temp=temp->next;    
            n++;
        }     

        ListNode *left = head;
        int rightIndex = n-2;
        int leftIndex = 0;
        ListNode *right = index[rightIndex];
        
        while(left != right && right->next && leftIndex<=rightIndex){
            temp = left->next;
            right->next->next = left->next;
            left->next = right->next;
            right->next = nullptr;
            rightIndex--;
            leftIndex++;
            left = temp;
            right = index[rightIndex];
        }
    }
};
