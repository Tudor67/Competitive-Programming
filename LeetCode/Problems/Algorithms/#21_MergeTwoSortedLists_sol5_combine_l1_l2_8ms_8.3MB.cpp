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
            ListNode* cur_min = (l1 != NULL ? l1 : l2);
            if(l1 != NULL && l2 != NULL){
                cur_min = (l1->val < l2->val ? l1 : l2);
            }
			
            ans->next = cur_min;
            ans = ans->next;
            
            if(cur_min == l1){
                l1 = l1->next;
            }else{
                l2 = l2->next;
            }
        }
        
        return ans_virtual_start->next;
    }
};