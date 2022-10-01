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
        // Step 1: create virtual/helper prevHead node that points to the head of the list
        ListNode* prevHead = new ListNode(0, head);
        
        // Step 2: node1: 0th node from prevHead
        //         node2: (n + 1)th node from prevHead
        ListNode* node1 = prevHead;
        ListNode* node2 = prevHead;
        for(int i = 1; i <= n + 1; ++i){
            node2 = node2->next;
        }
        
        // Step 3: shift by one unit node1 and node2 until node2 becomes nullptr
        //         in this way we maintain the invariant difference(node2, node1) == n + 1
        //         node1: (n + 1)th node from the end of the list
        //         node2: nullptr
        while(node2 != nullptr){
            node1 = node1->next;
            node2 = node2->next;
        }
        
        // Step 4: remove the nth node from the end of the list
        ListNode* nodeToRemove = node1->next;
        node1->next = nodeToRemove->next;
        nodeToRemove->next = nullptr;
        
        // Step 5: update the new head of the list
        //         remove the virtual/helper prevHead node
        head = prevHead->next;
        prevHead->next = nullptr;
        delete prevHead;
        
        return head;
    }
};