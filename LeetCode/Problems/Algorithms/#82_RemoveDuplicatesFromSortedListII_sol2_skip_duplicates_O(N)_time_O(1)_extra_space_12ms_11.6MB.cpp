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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* virtualHead = new ListNode();
        ListNode* predNode = virtualHead;
        ListNode* curNode = head;
        while(curNode != NULL){
            bool isDuplicate = false;
            while(curNode->next != NULL && curNode->val == curNode->next->val){
                isDuplicate = true;
                curNode = curNode->next;
            }
            if(!isDuplicate){
                predNode->next = curNode;
                predNode = curNode;
            }
            curNode = curNode->next;
        }
        predNode->next = NULL;
        return virtualHead->next;
    }
};