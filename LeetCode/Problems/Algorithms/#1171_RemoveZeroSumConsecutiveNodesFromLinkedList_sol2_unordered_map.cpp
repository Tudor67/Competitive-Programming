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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* virtual_start = new ListNode(0, head);
        unordered_map<int, ListNode*> pos;
        pos[0] = virtual_start;
        
        int pref_sum = 0;
        for(ListNode* node = head; node != NULL; node = node->next){
            pref_sum += node->val;
            if(pos.count(pref_sum)){
                ListNode* prev_node = pos[pref_sum];
                int s = pref_sum;
                for(ListNode* ptr = prev_node->next; ptr != node; ptr = ptr->next){
                    s += ptr->val;
                    pos.erase(s);
                }
                prev_node->next = node->next;
            }else{
                pos[pref_sum] = node;
            }
        }
        
        return virtual_start->next;
    }
};