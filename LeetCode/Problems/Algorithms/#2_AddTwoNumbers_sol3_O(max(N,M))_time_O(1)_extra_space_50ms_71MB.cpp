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
        ListNode* l3PrevHead = new ListNode();
        ListNode* l3Tail = l3PrevHead;
        
        int carry = 0;
        while(l1 != NULL || l2 != NULL || carry > 0){
            int digit1 = (l1 == NULL ? 0 : l1->val);
            int digit2 = (l2 == NULL ? 0 : l2->val);
            int digitSum = (digit1 + digit2 + carry);
            l3Tail->next = new ListNode(digitSum % 10);
            l3Tail = l3Tail->next;
            l1 = (l1 == NULL ? NULL : l1->next);
            l2 = (l2 == NULL ? NULL : l2->next);
            carry = digitSum / 10;
        }
        
        ListNode* l3Head = l3PrevHead->next;
        l3PrevHead->next = NULL;
        delete l3PrevHead;
        
        return l3Head;
    }
};