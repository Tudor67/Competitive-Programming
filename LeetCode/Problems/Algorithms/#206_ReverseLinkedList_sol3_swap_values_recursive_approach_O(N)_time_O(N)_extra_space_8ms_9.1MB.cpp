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
    ListNode* leftNode;
    bool swapValues;
    
    void rec(ListNode* rightNode){
        if(rightNode == NULL){
            return;
        }
        rec(rightNode->next);
        if(rightNode == leftNode || rightNode->next == leftNode){
            swapValues = false;
        }
        if(swapValues){
            swap(leftNode->val, rightNode->val);
            leftNode = leftNode->next;
        }
    }
    
public:
    ListNode* reverseList(ListNode* head) {
        leftNode = head;
        swapValues = true;
        rec(head);
        return head;
    }
};