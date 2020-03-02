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
        int min_val;
        
        while(l1 != NULL || l2 != NULL){
            min_val = (l1 != NULL ? l1->val : l2->val);
            if(l1 != NULL && l2 != NULL){
                min_val = min(l1->val, l2->val);
            }
            
            ans->next = new ListNode(min_val);
            ans = ans->next;
            if(l1 != NULL && min_val == l1->val){
                l1 = l1->next;
            }else{
                l2 = l2->next;
            }
        }
        
        return ans_virtual_start->next;
    }
};