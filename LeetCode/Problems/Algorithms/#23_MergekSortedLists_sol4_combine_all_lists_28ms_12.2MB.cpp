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
        priority_queue<pair<int, ListNode*>,
                       vector<pair<int, ListNode*>>,
                       greater<pair<int, ListNode*>>> pq;
        
        for(ListNode* l: lists){
            if(l != NULL){
                pq.push({l->val, l});
            }
        }
        
        while(!pq.empty()){
            ListNode* l = pq.top().second;
            pq.pop();
            
            if(l->next != NULL){
                pq.push({l->next->val, l->next});
            }
            
            ans->next = l;
            ans = ans->next;
            l = l->next;
        }
        
        return ans_virtual_start->next;
    }
};