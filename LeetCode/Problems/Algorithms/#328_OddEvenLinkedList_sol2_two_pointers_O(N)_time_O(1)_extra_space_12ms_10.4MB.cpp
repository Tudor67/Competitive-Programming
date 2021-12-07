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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL){
            return NULL;
        }
        
        ListNode* head2 = head->next;
        ListNode* tail1 = head;
        ListNode* tail2 = head->next;
        while(tail2 != NULL && tail2->next != NULL){
            tail1->next = tail1->next->next;
            tail2->next = tail2->next->next;
            tail1 = tail1->next;
            tail2 = tail2->next;
        }
        
        tail1->next = head2;
        
        return head;
    }
};