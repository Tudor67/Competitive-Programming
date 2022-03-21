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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* prevHead = new ListNode(INT_MIN, head);
        ListNode* p1 = prevHead;
        ListNode* p2 = prevHead->next;
        
        while(p2 != NULL){
            if(p2 != NULL && p2->next != NULL && p2->val == p2->next->val){
                int duplicateVal = p2->val;
                while(p2 != NULL && duplicateVal == p2->val){
                    ListNode* tempNode = p2;
                    p2 = p2->next;
                    tempNode->next = NULL;
                    delete tempNode;
                }
            }else{
                p1->next = p2;
                p1 = p1->next;
                p2 = p2->next;
            }
        }
        
        p1->next = NULL;
        
        head = prevHead->next;
        prevHead->next = NULL;
        delete prevHead;
        
        return head;
    }
};