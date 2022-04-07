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
    ListNode* kThNode(ListNode* node, int k){
        while(k > 1){
            node = node->next;
            k -= 1;
        }
        return node;
    }
    
public:
    ListNode* swapNodes(ListNode* head, int k) {
        int listSize = 0;
        for(ListNode* node = head; node != NULL; node = node->next){
            listSize += 1;
        }
        
        int firstPos = min(k, listSize + 1 - k);
        int secondPos = max(k, listSize + 1 - k);
        
        ListNode* firstNode = kThNode(head, firstPos);
        ListNode* secondNode = kThNode(head, secondPos);
        
        swap(firstNode->val, secondNode->val);
        
        return head;
    }
};