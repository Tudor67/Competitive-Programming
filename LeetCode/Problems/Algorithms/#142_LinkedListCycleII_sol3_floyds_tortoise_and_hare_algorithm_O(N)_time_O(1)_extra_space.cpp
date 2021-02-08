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
        ListNode* p1 = head;
        ListNode* p2 = head;
        bool hasCycle = false;
        while(!hasCycle && p2 != NULL && p2->next != NULL){
            p1 = p1->next;
            p2 = p2->next->next;
            if(p1 == p2){
                hasCycle = true;
            }
        }
        
        ListNode* cycleStart = NULL;
        if(hasCycle){
            cycleStart = head;
            while(cycleStart != p1){
                cycleStart = cycleStart->next;
                p1 = p1->next;
            }
        }
        
        return cycleStart;
    }
};