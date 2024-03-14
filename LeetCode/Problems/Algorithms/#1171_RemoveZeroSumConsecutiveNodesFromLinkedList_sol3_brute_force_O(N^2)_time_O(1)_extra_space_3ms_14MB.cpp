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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode prevHead(0, head);
        for(ListNode* a = &prevHead; a != nullptr; a = a->next){
            int sum = 0;
            for(ListNode* b = a->next; b != nullptr; b = b->next){
                sum += b->val;
                if(sum == 0){
                    a->next = b->next;
                }
            }
        }

        head = prevHead.next;
        prevHead.next = nullptr;

        return head;
    }
};