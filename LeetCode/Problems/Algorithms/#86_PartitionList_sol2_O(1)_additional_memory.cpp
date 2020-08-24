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
    ListNode* partition(ListNode* head, int x) {
        if(head != NULL){
            ListNode* l1_start = new ListNode();
            ListNode* l2_start = new ListNode();
            ListNode* l1 = l1_start;
            ListNode* l2 = l2_start;
            
            for(ListNode* node = head; node != NULL; node = node->next){
                if(node->val < x){
                    l1->next = node;
                    l1 = l1->next;
                }else{
                    l2->next = node;
                    l2 = l2->next;
                }
            }
            
            l2->next = NULL;
            l1->next = l2_start->next;
            head = l1_start->next;
        }
        
        return head;
    }
};