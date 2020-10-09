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
        ListNode* cycleStart = NULL;
        
        if(head != NULL){
            bool cycleFound = false;
            ListNode* slow = head;
            ListNode* fast = head;
            
            while(!cycleFound && fast != NULL && fast->next != NULL){
                slow = slow->next;
                fast = fast->next->next;
                if(slow == fast){
                    cycleFound = true;
                }
            }
            
            if(cycleFound){
                ListNode* p1 = head;
                ListNode* p2 = fast;
                while(p1 != p2){
                    p1 = p1->next;
                    p2 = p2->next;
                }
                cycleStart = p1;
            }
        }
        
        return cycleStart;
    }
};