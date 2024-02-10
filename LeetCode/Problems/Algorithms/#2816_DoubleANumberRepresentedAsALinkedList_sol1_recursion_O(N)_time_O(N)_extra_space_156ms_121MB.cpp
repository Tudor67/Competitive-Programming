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
private:
    void doubleIt(ListNode* node, int& carry){
        if(node != nullptr){
            doubleIt(node->next, carry);
            int sum = 2 * node->val + carry;
            node->val = sum % 10;
            carry = sum / 10;
        }
    }

public:
    ListNode* doubleIt(ListNode* head) {
        int carry = 0;
        
        doubleIt(head, carry);
        if(carry > 0){
            head = new ListNode(carry, head);
        }

        return head;
    }
};