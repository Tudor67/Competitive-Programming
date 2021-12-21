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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* prevHead = new ListNode(INT_MIN, head);
        ListNode* prevTail = prevHead;
        ListNode* tail = head;
        
        while(tail != NULL){
            ListNode* node = prevHead;
            while(node->next->val < tail->val){
                node = node->next;
            }
            
            if(node->next != tail){
                ListNode* tailNext = tail->next;
                tail->next = node->next;
                node->next = tail;
                prevTail->next = tailNext;
                tail = tailNext;
            }else{
                prevTail = tail;
                tail = tail->next;
            }
        }
        
        head = prevHead->next;
        prevHead->next = NULL;
        delete prevHead;
        
        return head;
    }
};