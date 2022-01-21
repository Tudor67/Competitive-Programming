/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        // Step 1: special case (list size <= 1) => return NULL
        if(head == NULL || head->next == NULL){
            return NULL;
        }
        
        // Step 2: check if there is a cycle (using slow and fast pointers)
        ListNode* slow = head;
        ListNode* fast = head;
        do{
            slow = slow->next;
            fast = fast->next->next;
        }while(fast != NULL && fast->next != NULL && slow != fast);
        
        if(slow == fast){
            // Step 3: there is a cycle => return the node where the cycle begins
            ListNode* p1 = head;
            ListNode* p2 = fast;
            while(p1 != p2){
                p1 = p1->next;
                p2 = p2->next;
            }
            return p1;
        }
        
        // Step 4: there is no cycle => return NULL
        return NULL;
    }
};