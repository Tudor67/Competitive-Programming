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
    ListNode* getTailOf(ListNode* head){
        ListNode* tail = head;
        while(tail != NULL && tail->next != NULL){
            tail = tail->next;
        }
        return tail;
    }
    
    ListNode* getMiddlePredecessor(ListNode* head, ListNode* tail){
        ListNode* p0 = head;
        ListNode* p1 = head;
        ListNode* p2 = head;
        while(p2 != tail && p2->next != tail){
            p0 = p1;
            p1 = p1->next;
            p2 = p2->next->next;
        }
        return p0;
    }
    
    TreeNode* bst(ListNode* head, ListNode* tail){
        if(head == NULL){
            return NULL;
        }
        if(head == tail){
            return new TreeNode(head->val);
        }
        ListNode* midPredecessor = getMiddlePredecessor(head, tail);
        ListNode* mid = midPredecessor->next;
        TreeNode* root = new TreeNode(mid->val);
        root->left = bst(head, midPredecessor);
        root->right = (mid == tail ? NULL : bst(mid->next, tail));
        return root;
    }
    
public:
    TreeNode* sortedListToBST(ListNode* head) {
        return bst(head, getTailOf(head));
    }
};