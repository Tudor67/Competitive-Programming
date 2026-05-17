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
    ListNode* rotateRight(ListNode* head, int k) {
        int listSize = 0;
        for(ListNode* node = head; node != nullptr; node = node->next){
            ++listSize;
        }

        if(listSize == 0 || k % listSize == 0){
            return head;
        }

        k = listSize - (k % listSize);

        ListNode* oldTail = head;
        while(oldTail->next != nullptr){
            oldTail = oldTail->next;
        }
        oldTail->next = head;

        ListNode* newTail = head;
        for(int i = 0; i < k - 1; ++i){
            newTail = newTail->next;
        }

        head = newTail->next;
        newTail->next = nullptr;

        return head;
    }
};