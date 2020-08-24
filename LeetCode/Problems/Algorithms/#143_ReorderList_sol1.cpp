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
        // Step 0: check is the list is empty
        if(head == NULL){
            return;
        }
        
        // Step 1: compute list_size
        int list_size = 0;
        for(ListNode* node = head; node != NULL; node = node->next){
            list_size += 1;
        }
        
        // Step 2: split the initial list into 2 sublists (p1 and p2)
        ListNode* p1_end = head;
        for(int i = 2; i <= list_size / 2 + list_size % 2; ++i){
            p1_end = p1_end->next;
        }
        
        ListNode* p2 = p1_end->next;
        ListNode* p1 = head;
        p1_end->next = NULL;
        
        // Step 3: reverse the second sublist (p2)
        ListNode* prev_node = NULL;
        ListNode* node = p2;
        ListNode* next_node;
        while(node != NULL){
            next_node = node->next;
            node->next = prev_node;
            prev_node = node;
            node = next_node;
        }
        p2 = prev_node;
        
        // Step 4: merge p1 and reversed p2
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