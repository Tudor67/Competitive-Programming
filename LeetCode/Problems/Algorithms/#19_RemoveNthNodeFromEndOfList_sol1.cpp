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
        ListNode* prev_node = virtual_start;
        ListNode* node = head;
        for(int i = 1; i <= list_size - n; ++i){
            prev_node = node;
            node = node->next;
        }
        prev_node->next = node->next;
        delete node;
        
        return virtual_start->next;
    }
};