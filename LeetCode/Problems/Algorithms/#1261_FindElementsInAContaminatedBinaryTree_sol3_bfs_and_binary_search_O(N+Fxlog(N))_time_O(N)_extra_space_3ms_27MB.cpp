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
    vector<int> sortedValues;

public:
    FindElements(TreeNode* root) {
        queue<pair<TreeNode*, int>> q;
        if(root != nullptr){
            q.push({root, 0});
        }

        while(!q.empty()){
            TreeNode* node = q.front().first;
            int val = q.front().second;
            q.pop();

            sortedValues.push_back(val);

            if(node->left != nullptr){
                q.push({node->left, 2 * val + 1});
            }
            if(node->right != nullptr){
                q.push({node->right, 2 * val + 2});
            }
        }
    }
    
    bool find(int target) {
        return binary_search(sortedValues.begin(), sortedValues.end(), target);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */