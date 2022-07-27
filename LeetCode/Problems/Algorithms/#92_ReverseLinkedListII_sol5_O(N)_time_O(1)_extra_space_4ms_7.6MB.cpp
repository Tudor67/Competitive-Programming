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
private:
    ListNode* next(ListNode* node, int k){
        while(k > 0){
            node = node->next;
            k -= 1;
        }
        return node;
    }
    
    void reverse(ListNode* head, ListNode* tail){
        ListNode* prevNode = NULL;
        ListNode* currentNode = head;
        while(prevNode != tail){
            ListNode* nextNode = currentNode->next;
            currentNode->next = prevNode;
            prevNode = currentNode;
            currentNode = nextNode;
        }
    }
    
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* prevHead = new ListNode(0, head);
        
        // Step 1: find the head of the sublist [left, right]: subHead
        ListNode* prevSubHead = next(prevHead, left - 1);
        ListNode* subHead = prevSubHead->next;
        
        // Step 2: find the tail of the sublist [left, right]: subTail
        ListNode* subTail = next(prevHead, right);
        ListNode* nextSubTail = subTail->next;
        
        // Step 3: reverse the sublist [left, right]
        reverse(subHead, subTail);
        
        // Step 4: link the reversed sublist to the initial list
        prevSubHead->next = subTail;
        subHead->next = nextSubTail;
        
        head = prevHead->next;
        prevHead->next = NULL;
        delete prevHead;
        
        return head;
    }
};