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
    ListNode* swapPairs(ListNode* head) {
        ListNode* prevHead = new ListNode();
        prevHead->next = head;

        ListNode* a = prevHead;
        while(a->next != nullptr && a->next->next != nullptr){
            ListNode* b = a->next;
            ListNode* c = b->next;
            ListNode* d = c->next;
            a->next = c;
            c->next = b;
            b->next = d;
            a = a->next->next;
        }

        head = prevHead->next;
        prevHead->next = nullptr;
        delete prevHead;

        return head;
    }
};