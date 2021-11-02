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
    void dfs(TreeNode* root, vector<TreeNode*>& dfsNodes){
        dfsNodes.push_back(root);
        if(root != NULL){
            dfs(root->left, dfsNodes);
            dfs(root->right, dfsNodes);
        }
    }
    
    bool sameValues(TreeNode* node1, TreeNode* node2){
        if(node1 == NULL || node2 == NULL){
            return (node1 == node2);
        }
        return (node1->val == node2->val);
    }
    
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        vector<TreeNode*> S;
        dfs(root, S);
        
        vector<TreeNode*> P;
        dfs(subRoot, P);
        
        vector<TreeNode*> PS;
        copy(P.begin(), P.end(), back_inserter(PS));
        PS.push_back(new TreeNode(INT_MIN));
        copy(S.begin(), S.end(), back_inserter(PS));
        
        const int SIZE = PS.size();
        vector<int> p(SIZE);
        for(int i = 1; i < SIZE; ++i){
            int k = p[i - 1];
            while(k > 0 && !sameValues(PS[k], PS[i])){
                k = p[k - 1];
            }
            if(sameValues(PS[k], PS[i])){
                p[i] = k + 1;
            }
            if(p[i] == (int)P.size()){
                return true;
            }
        }
        
        return false;
    }
};