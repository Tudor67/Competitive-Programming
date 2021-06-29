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
        ListNode* listPrevHead = new ListNode(0, head);
        ListNode* prevNode = listPrevHead;
        ListNode* curNode = head;
        ListNode* nextNode = NULL;
        
        int idx = 1;
        while(idx < left){
            prevNode = curNode;
            curNode = curNode->next;
            idx += 1;
        }
        
        ListNode* sublistPrevHead = prevNode;
        
        while(idx <= right){
            nextNode = curNode->next;
            curNode->next = prevNode;
            prevNode = curNode;
            curNode = nextNode;
            idx += 1;
        }
        
        sublistPrevHead->next->next = curNode;
        sublistPrevHead->next = prevNode;
        
        return listPrevHead->next;
    }
};