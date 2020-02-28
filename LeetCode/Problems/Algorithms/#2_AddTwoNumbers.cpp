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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans_start = new ListNode(0);
        ListNode* ans = ans_start;
        int carry = 0;
        
        while(l1 != NULL || l2 != NULL){
            int x = carry;
            
            if(l1 != NULL){
                x += l1->val;
                l1 = l1->next;
            }
            if(l2 != NULL){
                x += l2->val;
                l2 = l2->next;
            }
            
            ans->val = x % 10;
            carry = x / 10;
            
            if(l1 != NULL || l2 != NULL){
                ans->next = new ListNode(0);
                ans = ans->next;
            }
        }
        
        while(carry > 0){
            ans->next = new ListNode(carry % 10);
            carry /= 10;
            if(carry > 0){
                ans->next = new ListNode(0);
            }
        }
        
        return ans_start;
    }
};