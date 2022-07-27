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
        
        // find the start of the sublist [left, right]
        int index = 1;
        ListNode* prevNode = prevHead;
        ListNode* currentNode = head;
        while(index < left){
            prevNode = currentNode;
            currentNode = currentNode->next;
            index += 1;
        }
        
        ListNode* prevSubHead = prevNode;
        ListNode* subHead = currentNode;
        
        // reverse sublist
        while(index <= right){
            ListNode* nextNode = currentNode->next;
            currentNode->next = prevNode;
            prevNode = currentNode;
            currentNode = nextNode;
            index += 1;
        }
        ListNode* subTail = prevNode;
        ListNode* nextSubTail = currentNode;
        
        // link the reversed sublist to the initial list
        prevSubHead->next = subTail;
        subHead->next = nextSubTail;
        
        head = prevHead->next;
        prevHead->next = NULL;
        delete prevHead;
        
        return head;
    }
};