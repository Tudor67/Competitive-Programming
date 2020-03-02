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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* ans_virtual_start = new ListNode(0);
        ListNode* ans = ans_virtual_start;
        set<pair<int, ListNode*>> min_set;
        
        for(ListNode* l: lists){
            if(l != NULL){
                min_set.insert({l->val, l});
            }
        }
        
        while(!min_set.empty()){
            ListNode* l = (*min_set.begin()).second;
            min_set.erase({l->val, l});
            
            int min_val = l->val;
            if(l->next != NULL){
                min_set.insert({l->next->val, l->next});
            }
            l = l->next;
            
            ans->next = new ListNode(min_val);
            ans = ans->next;
        }
        
        return ans_virtual_start->next;
    }
};