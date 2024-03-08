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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* p2 = head;
        for(int i = 2; i <= n + 1; ++i){
            p2 = p2->next;
        }

        ListNode* newHead = nullptr;
        if(p2 == nullptr){
            newHead = head->next;
            head->next = nullptr;
        }else{
            newHead = head;
            ListNode* p1 = head;
            while(p2->next != nullptr){
                p2 = p2->next;
                p1 = p1->next;
            }
            ListNode* tempNode = p1->next;
            p1->next = p1->next->next;
            tempNode->next = nullptr;
        }

        return newHead;
    }
};