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
    static const hash<string> STR_HASH_OBJ;
    static const long long MODULO = 1e9 + 7;
    
    void computeSubtreeHashes(TreeNode* node,
                              unordered_map<TreeNode*, int>& subtreeToHash,
                              unordered_map<int, pair<TreeNode*, TreeNode*>>& hashToSubtrees){
        if(node == NULL){
            subtreeToHash[NULL] = STR_HASH_OBJ(to_string(INT_MIN));
        }else{
            computeSubtreeHashes(node->left, subtreeToHash, hashToSubtrees);
            computeSubtreeHashes(node->right, subtreeToHash, hashToSubtrees);
            string s = to_string(node->val) + "$" +
                       to_string(subtreeToHash[node->left]) + "$" +
                       to_string(subtreeToHash[node->right]) + "$";
            subtreeToHash[node] = STR_HASH_OBJ(s) % MODULO;
            if(hashToSubtrees.count(subtreeToHash[node])){
               hashToSubtrees[subtreeToHash[node]].second = node; 
            }else{
                hashToSubtrees[subtreeToHash[node]].first = node;
            }
        }
    }
    
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<TreeNode*, int> subtreeToHash;
        unordered_map<int, pair<TreeNode*, TreeNode*>> hashToSubtrees;
        computeSubtreeHashes(root, subtreeToHash, hashToSubtrees);
        
        vector<TreeNode*> duplicates;
        for(const pair<int, pair<TreeNode*, TreeNode*>>& HP: hashToSubtrees){
            const pair<TreeNode*, TreeNode*>& P = HP.second;
            if(P.second != NULL){
                duplicates.push_back(P.second);
            }
        }
        
        return duplicates;
    }
};