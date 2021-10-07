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
    TreeNode* predecessorNode;
    TreeNode* currentNode;
    
public:
    BSTIterator(TreeNode* root) {
        currentNode = root;
    }
    
    int next() {
        int val = INT_MIN;
        while(val == INT_MIN){
            if(currentNode->left == NULL){
                val = currentNode->val;
                currentNode = currentNode->right;
            }else{
                predecessorNode = currentNode->left;
                while(predecessorNode->right != NULL && predecessorNode->right != currentNode){
                    predecessorNode = predecessorNode->right;
                }
                if(predecessorNode->right == NULL){
                    predecessorNode->right = currentNode;
                    currentNode = currentNode->left;
                }else{
                    val = currentNode->val;
                    predecessorNode->right = NULL;
                    currentNode = currentNode->right;
                }
            }
        }
        return val;
    }
    
    bool hasNext() {
        return (currentNode != NULL);
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */