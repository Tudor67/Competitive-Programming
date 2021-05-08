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
    int getListSize(ListNode* head){
        int listSize = 0;
        for(ListNode* node = head; node != NULL; node = node->next){
            listSize += 1;
        }
        return listSize;
    }
    
    TreeNode* buildBST(ListNode*& head, int l, int r){
        TreeNode* root = NULL;
        if(l <= r){
            int mid = (l + r) / 2;
            root = new TreeNode();
            root->left = buildBST(head, l, mid - 1);
            root->val = head->val;
            head = head->next;
            root->right = buildBST(head, mid + 1, r);
        }
        return root;
    }
    
public:
    TreeNode* sortedListToBST(ListNode* head) {
        ListNode* tempHead = head;
        int listSize = getListSize(head);
        return buildBST(tempHead, 1, listSize);
    }
};