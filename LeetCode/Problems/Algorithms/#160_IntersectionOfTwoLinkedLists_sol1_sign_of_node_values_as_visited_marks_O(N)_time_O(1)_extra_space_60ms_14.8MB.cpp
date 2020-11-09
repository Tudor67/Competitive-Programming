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
        for(ListNode* node = headA; node != NULL; node = node->next){
            node->val = -node->val;
        }
        
        ListNode* headC = NULL;
        for(ListNode* node = headB; node != NULL; node = node->next){
            if(node->val < 0){
                headC = node;
                break;
            }
        }
        
        for(ListNode* node = headA; node != NULL; node = node->next){
            node->val = -node->val;
        }
        
        return headC;
    }
};