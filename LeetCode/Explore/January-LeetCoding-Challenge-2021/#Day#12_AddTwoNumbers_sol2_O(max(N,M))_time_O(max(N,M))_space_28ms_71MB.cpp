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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* virtualHead = new ListNode();
        ListNode* answerTail = virtualHead;
        int carry = 0;
        while(l1 != NULL || l2 != NULL || carry > 0){
            int val1 = (l1 == NULL ? 0 : l1->val);
            int val2 = (l2 == NULL ? 0 : l2->val);
            int sum = carry + val1 + val2;
            answerTail->next = new ListNode(sum % 10);
            answerTail = answerTail->next;
            carry = sum / 10;
            l1 = (l1 == NULL ? NULL : l1->next);
            l2 = (l2 == NULL ? NULL : l2->next);
        }
        return virtualHead->next;
    }
};