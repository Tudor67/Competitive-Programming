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
        if(head == NULL || head->next == NULL){
            return;
        }
        
        // compute list size
        int listSize = 0;
        for(ListNode* node = head; node != NULL; node = node->next){
            listSize += 1;
        }
        
        ListNode* node = head;
        for(int i = 2; i <= (listSize + 1) / 2; ++i){
            node = node->next;
        }
        
        // split original list into list1 and list2
        ListNode* head1 = head;
        ListNode* head2 = node->next;
        node->next = NULL;
        
        // reverse list2
        ListNode* prevNode = NULL;
        ListNode* tail2 = head2;
        while(tail2 != NULL){
            ListNode* nextNode = tail2->next;
            tail2->next = prevNode;
            prevNode = tail2;
            tail2 = nextNode;
        }
        tail2 = prevNode;
        
        // combine list1 with reversed list2
        ListNode* tail1 = head1;
        while(tail1 != NULL && tail2 != NULL){
            ListNode* tempNode1 = tail1->next;
            ListNode* tempNode2 = tail2->next;
            tail1->next = tail2;
            tail2->next = tempNode1;
            tail1 = tempNode1;
            tail2 = tempNode2;
        }
    }
};