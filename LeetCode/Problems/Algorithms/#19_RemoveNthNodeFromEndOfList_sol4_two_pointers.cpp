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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* virtual_start = new ListNode(0, head);
        ListNode* p1 = virtual_start;
        ListNode* p2 = virtual_start;
        
        for(int i = 1; i <= n + 1; ++i){
            p2 = p2->next;
        }
        
        while(p2 != NULL){
            p1 = p1->next;
            p2 = p2->next;
        }
        
        ListNode* temp = p1->next;
        p1->next = p1->next->next;
        delete temp;
        
        return virtual_start->next;
    }
};