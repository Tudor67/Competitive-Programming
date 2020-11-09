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
    ListNode* reverseList(ListNode* head) {
        ListNode* prevNode = NULL;
        ListNode* node = head;
        ListNode* nextNode = NULL;
        while(node != NULL){
            nextNode = node->next;
            node->next = prevNode;
            prevNode = node;
            node = nextNode;
        }
        return prevNode;
    }
};