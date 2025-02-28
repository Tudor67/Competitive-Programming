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
public:
    TreeNode* recoverFromPreorder(string traversal) {
        int val = 0;
        int depth = 0;
        queue<pair<int, int>> q;

        for(int i = 0; i < (int)traversal.length(); ++i){
            if(isdigit(traversal[i])){
                val = val * 10 + (traversal[i] - '0');
            }else{
                depth += 1;
            }

            if(isdigit(traversal[i]) && (i + 1 == (int)traversal.length() || traversal[i + 1] == '-')){
                q.push({val, depth});
                val = 0;
                depth = 0;
            }
        }
        
        TreeNode* root = new TreeNode(q.front().first);
        q.pop();

        stack<pair<TreeNode*, int>> st;
        st.push({root, 0});

        while(!q.empty()){
            int val = q.front().first;
            int depth = q.front().second;
            q.pop();

            while(st.top().second + 1 != depth){
                st.pop();
            }

            TreeNode* node = st.top().first;
            if(node->left == nullptr){
                node->left = new TreeNode(val);
                st.push({node->left, depth});
            }else{
                node->right = new TreeNode(val);
                st.push({node->right, depth});
            }
        }

        return root;
    }
};