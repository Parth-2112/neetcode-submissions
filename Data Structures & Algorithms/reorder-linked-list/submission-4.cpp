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
            temp = temp->next;
            n++;
        }

        temp = head;

        int i=0;
        int j=n-1;

        while(i+1 < j){
            index[i]->next = index[j];
            index[j]->next = index[i+1];
            index[j-1]->next = nullptr;
            i++;
            j--;
        }
        
    }
};
