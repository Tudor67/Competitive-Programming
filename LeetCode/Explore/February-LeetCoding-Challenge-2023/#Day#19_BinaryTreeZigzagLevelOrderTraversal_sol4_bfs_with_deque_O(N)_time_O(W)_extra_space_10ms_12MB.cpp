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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;

        deque<TreeNode*> dq;
        if(root != nullptr){
            dq.push_back(root);
        }

        while(!dq.empty()){
            res.push_back({});
            if((int)res.size() % 2 == 1){
                for(int i = dq.size(); i >= 1; --i){
                    TreeNode* node = dq.front();
                    dq.pop_front();

                    res.back().push_back(node->val);

                    for(TreeNode* child: {node->left, node->right}){
                        if(child != nullptr){
                            dq.push_back(child);
                        }
                    }
                }
            }else{
                for(int i = dq.size(); i >= 1; --i){
                    TreeNode* node = dq.back();
                    dq.pop_back();

                    res.back().push_back(node->val);

                    for(TreeNode* child: {node->right, node->left}){
                        if(child != nullptr){
                            dq.push_front(child);
                        }
                    }
                }
            }
        }

        return res;
    }
};