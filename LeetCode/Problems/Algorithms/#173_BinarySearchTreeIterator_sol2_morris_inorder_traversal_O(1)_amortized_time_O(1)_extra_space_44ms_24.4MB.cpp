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
class BSTIterator {
private:
    TreeNode* pred;
    TreeNode* cur;
    
public:
    BSTIterator(TreeNode* root) {
        cur = root;
    }
    
    int next() {
        int val = -1;
        while(val == -1){
            if(cur->left == NULL){
                val = cur->val;
                cur = cur->right;
            }else{
                for(pred = cur->left; pred->right != NULL && pred->right != cur; pred = pred->right);
                if(pred->right == NULL){
                    pred->right = cur;
                    cur = cur->left;
                }else{
                    val = cur->val;
                    pred->right = NULL;
                    cur = cur->right;
                }
            }
        }
        return val;
    }
    
    bool hasNext() {
        return (cur != NULL);
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */