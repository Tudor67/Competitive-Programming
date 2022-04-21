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
    TreeNode* curr;
    TreeNode* pred;
    
public:
    BSTIterator(TreeNode* root) {
        curr = root;
        pred = NULL;
    }
    
    ~BSTIterator(){
        // remove all 'pred->right = curr;' links
        while(hasNext()){
            next();
        }
    }
    
    int next() {
        int val = -1;
        while(curr != NULL){
            if(curr->left == NULL){
                val = curr->val;
                curr = curr->right;
                break;
            }else{
                pred = curr->left;
                while(pred->right != NULL && pred->right != curr){
                    pred = pred->right;
                }
                if(pred->right == NULL){
                    pred->right = curr;
                    curr = curr->left;
                }else{
                    val = curr->val;
                    pred->right = NULL;
                    curr = curr->right;
                    break;
                }
            }
        }
        return val;
    }
    
    bool hasNext() {
        return (curr != NULL);
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */