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
class FindElements {
private:
    TreeNode* root;

    void recover(TreeNode* node, int x){
        if(node == nullptr){
            return;
        }
        node->val = x;
        recover(node->left, 2 * x + 1);
        recover(node->right, 2 * x + 2);
    }

public:
    FindElements(TreeNode* root) {
        this->root = root;
        recover(root, 0);
    }
    
    bool find(int target) {
        TreeNode* node = root;
        int msb = 31 - __builtin_clz((unsigned int)(target + 1));
        for(int bit = msb - 1; bit >= 0 && node != nullptr; --bit){
            if(((target + 1) >> bit) & 1){
                node = node->right;
            }else{
                node = node->left;
            }
        }
        return (node != nullptr && node->val == target);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */