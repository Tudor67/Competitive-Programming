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
    ListNode* insertionSortList(ListNode* head) { 
        ListNode* answer_virtual_start = new ListNode(0);
        for(ListNode* node = head; node != NULL; node = node->next){
            ListNode* p = answer_virtual_start;
            while(p->next != NULL && p->next->val < node->val){
                p = p->next;
            }
            ListNode* temp = p->next;
            p->next = new ListNode(node->val, temp);
        }
        return answer_virtual_start->next;
    }
};