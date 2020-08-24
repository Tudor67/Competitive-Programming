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
    ListNode* swapPairs(ListNode* head) {
        ListNode* virtual_start = new ListNode(0, head);
        ListNode* p0 = virtual_start;
        
        while(p0->next != NULL && p0->next->next != NULL){
            ListNode* p1 = p0->next;
            ListNode* p2 = p0->next->next;
            p1->next = p2->next;
            p2->next = p1;
            p0->next = p2;
            p0 = p0->next->next;
        }
        
        return virtual_start->next;
    }
};