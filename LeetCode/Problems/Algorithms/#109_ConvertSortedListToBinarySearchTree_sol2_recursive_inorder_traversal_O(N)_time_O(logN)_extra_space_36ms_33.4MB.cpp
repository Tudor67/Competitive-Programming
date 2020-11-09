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
    ListNode* head;
    
    int getListSize(ListNode* head){
        int listSize = 0;
        for(ListNode* node = head; node != NULL; node = node->next){
            listSize += 1;
        }
        return listSize;
    }
    
    TreeNode* buildBST(int startPos, int endPos){
        if(startPos > endPos){
            return NULL;
        }
        
        TreeNode* root = new TreeNode();
        int mid = (startPos + endPos) / 2;
        
        // left subtree
        root->left = buildBST(startPos, mid - 1);
        
        // root
        root->val = head->val;
        head = head->next;
        
        // right subtree
        root->right = buildBST(mid + 1, endPos);
        
        return root;
    }
    
public:
    TreeNode* sortedListToBST(ListNode* head) {
        this->head = head;
        int startPos = 1;
        int endPos = getListSize(head);
        return buildBST(startPos, endPos);
    }
};