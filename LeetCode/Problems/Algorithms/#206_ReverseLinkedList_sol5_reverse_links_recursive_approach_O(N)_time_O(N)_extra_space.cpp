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
    void reverseList(ListNode* prevNode, ListNode* curNode, ListNode*& reverseHead){
        if(curNode == NULL){
            reverseHead = prevNode;
        }else{
            reverseList(curNode, curNode->next, reverseHead);
            curNode->next = prevNode;
        }
    }
    
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* reverseHead = NULL;
        reverseList(NULL, head, reverseHead);
        return reverseHead;
    }
};