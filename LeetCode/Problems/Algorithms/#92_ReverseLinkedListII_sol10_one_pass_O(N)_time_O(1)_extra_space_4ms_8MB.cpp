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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* prevHead = new ListNode(0, head);

        ListNode* prevLeftNode = prevHead;
        for(int i = 1; i <= left - 1; ++i){
            prevLeftNode = prevLeftNode->next;
        }

        ListNode* tail = prevLeftNode->next;
        for(int i = left; i <= right - 1; ++i){
            ListNode* nextTail = tail->next;
            tail->next = nextTail->next;
            nextTail->next = prevLeftNode->next;
            prevLeftNode->next = nextTail;
        }

        head = prevHead->next;
        prevHead->next = nullptr;
        delete prevHead;

        return head;
    }
};