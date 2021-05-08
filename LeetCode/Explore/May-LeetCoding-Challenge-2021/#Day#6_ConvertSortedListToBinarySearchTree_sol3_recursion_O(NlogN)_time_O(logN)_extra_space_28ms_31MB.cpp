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
    ListNode* getMidNode(ListNode* head, ListNode* tail){
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != tail && fast->next != tail){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    
    TreeNode* sortedListToBST(ListNode* head, ListNode* tail){
        TreeNode* root = NULL;
        if(head != tail){
            ListNode* mid = getMidNode(head, tail);
            root = new TreeNode(mid->val);
            root->left = sortedListToBST(head, mid);
            root->right = sortedListToBST(mid->next, tail);
        }
        return root;
    }
    
public:
    TreeNode* sortedListToBST(ListNode* head) {
        return sortedListToBST(head, NULL);
    }
};