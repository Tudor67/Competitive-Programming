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

        k %= listSize;

        ListNode* p2 = head;
        for(int i = 0; i < k; ++i){
            p2 = p2->next;
        }

        ListNode* p1 = head;
        while(p2->next != nullptr){
            p1 = p1->next;
            p2 = p2->next;
        }
        
        p2->next = head;
        head = p1->next;
        p1->next = nullptr;

        return head;
    }
};