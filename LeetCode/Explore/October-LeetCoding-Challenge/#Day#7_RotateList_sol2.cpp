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
        int listSize = 0;
        for(ListNode* node = head; node != NULL; node = node->next){
            listSize += 1;
        }
        
        if(listSize > 0 && k % listSize > 0){
            k %= listSize;
            ListNode* node = head;
            for(int i = 1; i <= listSize - k - 1; ++i){
                node = node->next;
            }
            ListNode* newHead = node->next;
            node->next = NULL;
            node = newHead;
            while(node->next != NULL){
                node = node->next;
            }
            node->next = head;
            head = newHead;
        }
        
        return head;
    }
};