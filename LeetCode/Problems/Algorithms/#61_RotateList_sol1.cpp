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
    ListNode* rotateRight(ListNode* head, int k) {
        int list_size = 0;
        for(ListNode* node = head; node != NULL; node = node->next){
            list_size += 1;
        }
        
        if(list_size > 0 && k % list_size > 0){
            k = k % list_size;
            
            ListNode* tail = head;
            for(; tail->next != NULL; tail = tail->next);
            tail->next = head;
            
            for(int i = 2; i <= list_size - k; ++i){
                head = head->next;
            }
            
            ListNode* temp = head;
            head = head->next;
            temp->next = NULL;
        }
        
        return head;
    }
};