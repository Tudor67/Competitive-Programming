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
    ListNode* reverseList(ListNode* node){
        ListNode* prevNode = nullptr;
        ListNode* nextNode = nullptr;
        while(node != nullptr){
            nextNode = node->next;
            node->next = prevNode;
            prevNode = node;
            node = nextNode;
        }
        return prevNode;
    }

public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* l1Rev = reverseList(l1);
        ListNode* l2Rev = reverseList(l2);

        int carry = 0;
        ListNode* p1 = l1Rev;
        ListNode* p2 = l2Rev;
        ListNode* res = nullptr;

        while(p1 != nullptr || p2 != nullptr || carry > 0){
            int digit1 = (p1 == nullptr ? 0 : p1->val);
            int digit2 = (p2 == nullptr ? 0 : p2->val);
            int sum = carry + digit1 + digit2;

            res = new ListNode(sum % 10, res);
            if(p1 != nullptr){
                p1 = p1->next;
            }
            if(p2 != nullptr){
                p2 = p2->next;
            }
            carry = sum / 10;
        }

        l1 = reverseList(l1Rev);
        l2 = reverseList(l2Rev);
        
        return res;
    }
};