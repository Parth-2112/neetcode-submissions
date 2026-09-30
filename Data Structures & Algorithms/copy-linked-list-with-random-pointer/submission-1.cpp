/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        unordered_map<Node*, int> lookup;
        unordered_map<int, Node*> newLookup;

        int n = 0;
        Node *temp = head;
        Node dummy(0);

        while (temp) {
            lookup[temp] = n; 
            n++;
            temp = temp->next;
        }

        temp = head;
        Node *newTemp = &dummy;

        for (int i = 0; i < n; i++) {
            Node* newNode = new Node(temp->val);  
            newTemp->next = newNode;
            newTemp = newTemp->next;
            temp = temp->next;
            newLookup[i] = newTemp;    
        }

        temp = head;
        newTemp = dummy.next; 

        for (int i = 0; i < n; i++) {
            if (temp->random) {                       
                int idx = lookup[temp->random];       
                newTemp->random = newLookup[idx];     
            }
            temp = temp->next;          
            newTemp = newTemp->next;    
        }

        return dummy.next;              
    }
};
