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
    int computeListSize(ListNode* head){
        int listSize = 0;
        for(ListNode* node = head; node != nullptr; node = node->next){
            listSize += 1;
        }
        return listSize;
    }

    ListNode* kthNode(ListNode* head, int k){
        ListNode* node = head;
        for(int i = 1; i <= k - 1 && node != nullptr; ++i){
            node = node->next;
        }
        return node;
    }

public:
    ListNode* swapNodes(ListNode* head, int k) {
        int listSize = computeListSize(head);
        ListNode* firstNode = kthNode(head, k);
        ListNode* secondNode = kthNode(head, listSize - k + 1);
        swap(firstNode->val, secondNode->val);
        return head;
    }
};