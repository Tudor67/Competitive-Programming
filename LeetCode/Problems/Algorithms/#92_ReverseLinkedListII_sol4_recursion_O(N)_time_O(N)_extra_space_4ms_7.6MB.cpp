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
    void reverse(ListNode* node, int idx, ListNode*& leftNode, int& left, int& right){
        if(idx < right){
            if(idx < left){
                leftNode = leftNode->next;
            }
            reverse(node->next, idx + 1, leftNode, left, right);
        }
        if(left < right){
            swap(leftNode->val, node->val);
            leftNode = leftNode->next;
            left += 1;
            right -= 1;
        }
    }
    
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* leftNode = head;
        reverse(head, 1, leftNode, left, right);
        return head;
    }
};