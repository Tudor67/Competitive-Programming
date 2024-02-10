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
    ListNode* doubleIt(ListNode* head) {
        if(head->val >= 5){
            head = new ListNode(0, head);
        }
        for(ListNode* node = head; node != nullptr; node = node->next){
            node->val = 2 * node->val % 10;
            if(node->next != nullptr && node->next->val >= 5){
                node->val += 1;
            }
        }
        return head;
    }
};