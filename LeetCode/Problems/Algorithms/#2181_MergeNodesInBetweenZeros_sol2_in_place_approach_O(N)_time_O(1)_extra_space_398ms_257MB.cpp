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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* p1 = head;
        for(ListNode* p2 = head->next; p2 != nullptr; p2 = p2->next){
            p1->val += p2->val;
            if(p2->val == 0 && p2->next != nullptr){
                p1 = p1->next;
                p1->val = 0;
            }
        }
        p1->next = nullptr;
        return head;
    }
};