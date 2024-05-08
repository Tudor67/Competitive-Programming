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
    ListNode* reverse(ListNode* head){
        ListNode* prevNode = nullptr;
        ListNode* currNode = head;
        ListNode* nextNode = nullptr;
        while(currNode != nullptr){
            nextNode = currNode->next;
            currNode->next = prevNode;
            prevNode = currNode;
            currNode = nextNode;
        }
        return prevNode;
    }

public:
    ListNode* doubleIt(ListNode* head) {
        ListNode* revHead = reverse(head);

        int carry = 0;
        ListNode* prevNode = nullptr;
        ListNode* currNode = revHead;
        while(currNode != nullptr){
            int sum = 2 * currNode->val + carry;
            currNode->val = sum % 10;
            carry = sum / 10;
            prevNode = currNode;
            currNode = currNode->next;
        }

        if(carry > 0){
            prevNode->next = new ListNode(carry);
        }

        return reverse(revHead);
    }
};