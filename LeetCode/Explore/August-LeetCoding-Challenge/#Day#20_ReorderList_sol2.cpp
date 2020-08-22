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
    void reorderList(ListNode* head) {
        // compute list size of L
        int list_size = 0;
        for(ListNode* node = head; node != NULL; node = node->next){
            list_size += 1;
        }
        
        // compute the start of L2
        ListNode* p2 = head;
        for(int i = 2; i <= list_size / 2 + 1; ++i){
            p2 = p2->next;
        }
        
        // reverse L2
        ListNode* prev_node = NULL;
        while(p2 != NULL){
            ListNode* temp = p2->next;
            p2->next = prev_node;
            prev_node = p2;
            p2 = temp;
        }
        p2 = prev_node;
        
        // merge L1 with reversed L2
        ListNode* p1 = head;
        while(p1 != NULL || p2 != NULL){
            if(p1 != NULL){
                ListNode* temp = p1->next;
                p1->next = p2;
                p1 = temp;
            }
            if(p2 != NULL){
                ListNode* temp = p2->next;
                p2->next = p1;
                p2 = temp;
            }
        }
    }
};