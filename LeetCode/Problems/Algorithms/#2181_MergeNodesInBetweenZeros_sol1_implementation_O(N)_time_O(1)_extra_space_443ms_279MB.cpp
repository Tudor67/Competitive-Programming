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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* prevResHead = new ListNode(0);
        ListNode* resTail = prevResHead;

        ListNode* currNode = head->next;
        while(currNode != nullptr){
            int sum = 0;
            while(currNode->val != 0){
                sum += currNode->val;
                currNode = currNode->next;
            }
            currNode = currNode->next;
            resTail->next = new ListNode(sum);
            resTail = resTail->next;
        }
        
        ListNode* resHead = prevResHead->next;
        prevResHead->next = nullptr;
        delete prevResHead;

        return resHead;
    }
};