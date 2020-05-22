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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL){
            return NULL;
        }
        
        // search
        ListNode* last_odd = head;
        while(last_odd->next != NULL && last_odd->next->next != NULL){
            last_odd = last_odd->next->next;
        }
        ListNode* even_after_last_odd = last_odd->next;
        
        // merge
        ListNode* p1 = head;
        ListNode* p2 = last_odd;
        while(p1 != last_odd){
            p2->next = p1->next;
            p2 = p2->next;
            p1->next = p2->next;
            p1 = p1->next;
        }
        p2->next = even_after_last_odd;
        
        return head;
    }
};