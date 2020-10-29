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
    ListNode* detectCycle(ListNode* head) {
        if(head == NULL){
            return NULL;
        }
        
        ListNode* virtualHead = new ListNode(0);
        virtualHead->next = head;
        
        ListNode* slow = virtualHead->next;
        ListNode* fast = virtualHead->next->next;
        while(slow != fast && fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode* cycleStart = NULL;
        if(slow == fast){
            ListNode* p1 = virtualHead;
            ListNode* p2 = fast;
            while(p1 != p2){
                p1 = p1->next;
                p2 = p2->next;
            }
            cycleStart = p2;
        }
        
        return cycleStart;
    }
};