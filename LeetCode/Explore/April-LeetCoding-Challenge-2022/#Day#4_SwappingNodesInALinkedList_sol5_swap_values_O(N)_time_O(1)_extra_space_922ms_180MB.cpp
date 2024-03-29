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
        ListNode* firstNode = head;
        for(int i = 1; i <= k - 1; ++i){
            firstNode = firstNode->next;
        }
        
        ListNode* secondNode = head;
        for(ListNode* node = firstNode; node->next != NULL; node = node->next){
            secondNode = secondNode->next;
        }
        
        swap(firstNode->val, secondNode->val);
        
        return head;
    }
};