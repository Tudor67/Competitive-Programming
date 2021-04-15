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
    ListNode* partition(ListNode* head, int x) {
        ListNode* l1Tail = new ListNode();
        ListNode* l2Tail = new ListNode();
        ListNode* l1VirtualHead = l1Tail;
        ListNode* l2VirtualHead = l2Tail;
        for(ListNode* node = head; node != NULL; node = node->next){
            if(node->val < x){
                l1Tail->next = node;
                l1Tail = l1Tail->next;
            }else{
                l2Tail->next = node;
                l2Tail = l2Tail->next;
            }
        }
        l2Tail->next = NULL;
        l1Tail->next = l2VirtualHead->next;
        return l1VirtualHead->next;
    }
};