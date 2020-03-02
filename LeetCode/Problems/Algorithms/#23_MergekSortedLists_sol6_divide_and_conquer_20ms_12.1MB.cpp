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
    ListNode* merge2Lists(ListNode* l1, ListNode* l2){
        ListNode* ans_virtual_start = new ListNode(0);
        ListNode* ans = ans_virtual_start;
        ListNode* cur_min;
            
        while(l1 != NULL || l2 != NULL){
            cur_min = (l1 != NULL ? l1 : l2);
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
        
        ans = ans_virtual_start->next;
        delete ans_virtual_start;
        return ans;
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        for(int step_size = 1; step_size < (int)lists.size(); step_size *= 2){
            for(int i = 0; i + step_size < (int)lists.size(); i += 2 * step_size){
                lists[i] = merge2Lists(lists[i], lists[i + step_size]);
            }
        }
        return lists.empty() ? NULL : lists[0];
    }
};