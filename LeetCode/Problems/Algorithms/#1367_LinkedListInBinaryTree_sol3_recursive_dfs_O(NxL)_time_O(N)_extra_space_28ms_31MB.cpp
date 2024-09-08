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
    bool isMatching(ListNode* head, TreeNode* root) {
        if(head == nullptr){
            return true;
        }
        if(root == nullptr){
            return false;
        }
        if(root->val == head->val){
            return (isMatching(head->next, root->left) ||
                    isMatching(head->next, root->right));
        }
        return false;
    }

public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        if(isMatching(head, root)){
            return true;
        }
        if(root == nullptr){
            return false;
        }
        return (isSubPath(head, root->left) ||
                isSubPath(head, root->right));
    }
};