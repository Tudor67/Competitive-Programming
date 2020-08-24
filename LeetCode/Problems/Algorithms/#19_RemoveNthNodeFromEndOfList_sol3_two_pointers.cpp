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
        ListNode* p0 = virtual_start;
        ListNode* p1 = head;
        ListNode* p2 = head;
        
        for(int i = 2; i <= n + 1; ++i){
            p2 = p2->next;
        }
        
        while(p2 != NULL){
            p0 = p0->next;
            p1 = p1->next;
            p2 = p2->next;
        }
        
        p0->next = p1->next;
        delete p1;
        
        return virtual_start->next;
    }
};