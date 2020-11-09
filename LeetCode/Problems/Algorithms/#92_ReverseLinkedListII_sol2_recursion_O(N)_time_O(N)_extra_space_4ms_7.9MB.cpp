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
    int remainingSwaps;
    
    void rec(int m, ListNode* rightNode, int n){
        if(m > 1){
            leftNode = leftNode->next;
            rec(m - 1, rightNode->next, n - 1);
        }
        if(m == 1 && n > 1){
            rec(m, rightNode->next, n - 1);
        }
        if(remainingSwaps > 0){
            remainingSwaps -= 1;
            swap(leftNode->val, rightNode->val);
            leftNode = leftNode->next;
        }
    }
    
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        leftNode = head;
        remainingSwaps = (n - m + 1) / 2;
        rec(m, head, n);
        return head;
    }
};