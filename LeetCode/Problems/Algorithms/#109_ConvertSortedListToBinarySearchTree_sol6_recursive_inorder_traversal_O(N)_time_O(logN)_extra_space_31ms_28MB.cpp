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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
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

    TreeNode* sortedListToBST(ListNode*& currentListNode, int firstPos, int lastPos){
        if(firstPos > lastPos){
            return nullptr;
        }else{
            int midPos = (firstPos + lastPos) / 2;
            TreeNode* leftBST = sortedListToBST(currentListNode, firstPos, midPos - 1);
            int rootVal = currentListNode->val;
            currentListNode = currentListNode->next;
            TreeNode* rightBST = sortedListToBST(currentListNode, midPos + 1, lastPos);
            return new TreeNode(rootVal, leftBST, rightBST);
        }
    }

public:
    TreeNode* sortedListToBST(ListNode* head) {
        return sortedListToBST(head, 0, computeListSize(head) - 1);
    }
};