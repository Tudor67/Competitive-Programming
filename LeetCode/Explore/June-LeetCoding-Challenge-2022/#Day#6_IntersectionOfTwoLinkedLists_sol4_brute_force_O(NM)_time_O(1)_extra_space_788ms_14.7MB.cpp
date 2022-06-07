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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        for(ListNode* nodeA = headA; nodeA != NULL; nodeA = nodeA->next){
            for(ListNode* nodeB = headB; nodeB != NULL; nodeB = nodeB->next){
                if(nodeB == nodeA){
                    return nodeA;
                }
            }
        }
        return NULL;
    }
};