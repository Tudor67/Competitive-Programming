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
    int getListSize(ListNode* head){
        int listSize = 0;
        for(ListNode* node = head; node != NULL; node = node->next){
            listSize += 1;
        }
        return listSize;
    }
    
    ListNode* getListNode(ListNode* head, int k){
        ListNode* node = head;
        for(int i = 1; i <= k - 1 && node != NULL; ++i){
            node = node->next;
        }
        return node;
    }
    
public:
    ListNode* swapNodes(ListNode* head, int k) {
        const int N = getListSize(head);
        ListNode* firstNode = getListNode(head, k);
        ListNode* secondNode = getListNode(head, N - k + 1);
        swap(firstNode->val, secondNode->val);
        return head;
    }
};