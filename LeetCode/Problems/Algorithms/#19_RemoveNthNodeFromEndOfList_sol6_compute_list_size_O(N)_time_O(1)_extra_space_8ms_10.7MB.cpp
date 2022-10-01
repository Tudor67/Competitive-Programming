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
        // Step 1: compute listSize
        int listSize = 0;
        for(ListNode* node = head; node != nullptr; node = node->next){
            listSize += 1;
        }
        
        // Step 2: create the virtual/helper node prevHead that points to the head of the list
        //         compute the (n + 1)th node from the end of the list
        ListNode* prevHead = new ListNode(0, head);
        ListNode* node = prevHead;
        for(int i = 1; i <= listSize - n; ++i){
            node = node->next;
        }
        
        // Step 3: remove the nth node from the end of the list
        ListNode* nodeToRemove = node->next;
        node->next = nodeToRemove->next;
        nodeToRemove->next = nullptr;
        
        // Step 4: update the new head of the list
        //         delete the virtual/helper prevHead node
        head = prevHead->next;
        prevHead->next = nullptr;
        delete prevHead;
        
        return head;
    }
};