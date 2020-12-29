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
        int listSize = 0;
        for(ListNode* node = head; node != NULL; node = node->next){
            listSize += 1;
        }
        
        ListNode* virtualHead = new ListNode(0, head);
        ListNode* prevNode = virtualHead;
        ListNode* curNode = head;
        for(int iteration = 1; iteration <= listSize / 2; ++iteration){
            ListNode* p1 = curNode;
            ListNode* p2 = curNode->next;
            p1->next = p2->next;
            p2->next = p1;
            prevNode->next = p2;
            prevNode = p1;
            curNode = p1->next;
        }
        
        return virtualHead->next;
    }
};