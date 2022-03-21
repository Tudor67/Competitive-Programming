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
private:
    int computeListSize(ListNode* head){
        int listSize = 0;
        for(ListNode* node = head; node != NULL; node = node->next){
            listSize += 1;
        }
        return listSize;
    }
    
public:
    ListNode* rotateRight(ListNode* head, int k) {
        int listSize = computeListSize(head);
        if(head == NULL || k % listSize == 0){
            return head;
        }
        
        k %= listSize;
        
        // split into two sublists
        ListNode* node = head;
        for(int i = 1; i <= listSize - k - 1; ++i){
            node = node->next;
        }
        
        ListNode* newHead = node->next;
        node->next = NULL;
        
        // connect the second sublist with the first sublist
        node = newHead;
        while(node->next != NULL){
            node = node->next;
        }
        
        node->next = head;
        
        return newHead;
    }
};