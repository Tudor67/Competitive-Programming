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
        ListNode* currNode = head;
        ListNode* prevNode = nullptr;
        while(currNode != nullptr){
            ListNode* nextNode = currNode->next;
            currNode->next = prevNode;
            prevNode = currNode;
            currNode = nextNode;
        }
        return prevNode;
    }

public:
    ListNode* doubleIt(ListNode* head) {
        // Step 1: reverse the list
        ListNode* revHead = reverse(head);
        ListNode* revTail = nullptr;

        // Step 2: double the reversed list
        int carry = 0;
        for(ListNode* node = revHead; node != nullptr; node = node->next){
            int sum = 2 * node->val + carry;
            node->val = sum % 10;
            carry = sum / 10;
            revTail = node;
        }

        if(carry > 0){
            revTail->next = new ListNode(carry);
        }

        // Step 3: reverse the reversed list
        head = reverse(revHead);

        return head;
    }
};