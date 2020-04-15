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
    ListNode* middleNode(ListNode* head) {
        ListNode* node = head;
        int size = 0;
        while(node != NULL){
            ++size;
            node = node->next;
        }
        
        node = head;
        for(int i = 0; i < size / 2; ++i){
            node = node->next;
        }
        
        return node;
    }
};