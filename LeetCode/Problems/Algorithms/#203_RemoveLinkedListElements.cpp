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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* virtual_start = new ListNode(0, head);
        ListNode* prev_node = virtual_start;
        ListNode* node = head;
        while(node != NULL){
            if(node->val == val){
                prev_node->next = node->next;
                delete node;
                node = prev_node->next;
            }else{
                prev_node = node;
                node = node->next;
            }
        }
        return virtual_start->next;
    }
};