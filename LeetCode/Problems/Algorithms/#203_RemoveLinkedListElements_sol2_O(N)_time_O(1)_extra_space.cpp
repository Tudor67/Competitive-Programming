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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* prevHead = new ListNode(INT_MIN, head);
        ListNode* prevNode = prevHead;
        ListNode* node = head;
        
        while(node != NULL){
            if(node->val == val){
                prevNode->next = node->next;
                node->next = NULL;
                delete node;
            }else{
                prevNode = node;
            }
            node = prevNode->next;
        }
        
        head = prevHead->next;
        prevHead->next = NULL;
        delete prevHead;
        
        return head;
    }
};