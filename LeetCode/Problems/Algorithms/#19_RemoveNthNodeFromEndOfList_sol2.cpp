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
        int list_size = 0;
        for(ListNode* node = head; node != NULL; node = node->next){
            list_size += 1;
        }
        
        ListNode* virtual_start = new ListNode(0, head);
        ListNode* node = virtual_start;
        for(int i = 1; i <= list_size - n; ++i){
            node = node->next;
        }
        
        ListNode* temp = node->next;
        node->next = node->next->next;
        delete temp;
        
        return virtual_start->next;
    }
};