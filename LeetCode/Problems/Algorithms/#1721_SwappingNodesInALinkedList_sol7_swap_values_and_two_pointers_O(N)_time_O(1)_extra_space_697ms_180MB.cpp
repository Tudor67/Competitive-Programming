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
    ListNode* swapNodes(ListNode* head, int k) {
        // firstNode: the kth node of the input list
        ListNode* firstNode = head;
        while(k > 1){
            k -= 1;
            firstNode = firstNode->next;
        }

        // secondNode: the (N - k + 1)th node of the input list
        ListNode* secondNode = head;
        for(ListNode* node = firstNode->next; node != nullptr; node = node->next){
            secondNode = secondNode->next;
        }

        // swap values of firstNode and secondNode
        swap(firstNode->val, secondNode->val);

        return head;
    }
};