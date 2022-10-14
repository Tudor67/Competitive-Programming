/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* prevNode = node;
        while(node->next != nullptr){
            prevNode = node;
            node->val = node->next->val;
            node = node->next;
        }
        prevNode->next = nullptr;
    }
};