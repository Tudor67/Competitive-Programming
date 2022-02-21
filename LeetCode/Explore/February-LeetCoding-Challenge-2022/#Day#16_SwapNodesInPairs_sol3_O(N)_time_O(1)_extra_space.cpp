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
        ListNode* prevHead = new ListNode(0, head);
        
        ListNode* prevNode = prevHead;
        ListNode* curNode = head;
        while(curNode != NULL && curNode->next != NULL){
            ListNode* nextNode = curNode->next;
            ListNode* nextNextNode = curNode->next->next;
            nextNode->next = curNode;
            curNode->next = nextNextNode;
            prevNode->next = nextNode;
            prevNode = curNode;
            curNode = curNode->next;
        }
        
        head = prevHead->next;
        prevHead->next = NULL;
        delete prevHead;
        
        return head;
    }
};