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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* ans_virtual_start = new ListNode(0);
        ListNode* ans = ans_virtual_start;
        
        while(l1 != NULL || l2 != NULL){
            int min_val;
            if(l1 != NULL && l2 != NULL){
                //p_min = (l1->val < l2->val ? l1 : l2);
                if(l1->val < l2->val){
                    min_val = l1->val;
                    l1 = l1->next;
                }else{
                    min_val = l2->val;
                    l2 = l2->next;
                }
            }else{
                //p_min = (l1 != NULL ? l1 : l2);
                if(l1 != NULL){
                    min_val = l1->val;
                    l1 = l1->next;
                }else{
                    min_val = l2->val;
                    l2 = l2->next;
                }
            }
            
            ans->next = new ListNode(min_val);
            ans = ans->next;
        }
        
        return ans_virtual_start->next;
    }
};