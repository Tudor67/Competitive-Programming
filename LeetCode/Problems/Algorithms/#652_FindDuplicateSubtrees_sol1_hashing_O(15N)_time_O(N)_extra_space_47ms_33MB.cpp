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
    void computeSubtreeHashes(TreeNode* node,
                              unordered_map<string, int>& subtreeIdx,
                              unordered_map<TreeNode*, int>& subtreeToHash,
                              unordered_map<int, pair<TreeNode*, TreeNode*>>& hashToSubtrees){
        if(node == NULL){
            subtreeToHash[NULL] = -1;
        }else{
            computeSubtreeHashes(node->left, subtreeIdx, subtreeToHash, hashToSubtrees);
            computeSubtreeHashes(node->right, subtreeIdx, subtreeToHash, hashToSubtrees);
            string s = to_string(node->val) + "$" +
                       to_string(subtreeToHash[node->left]) + "$" +
                       to_string(subtreeToHash[node->right]) + "$";
            if(!subtreeIdx.count(s)){
                int newIdx = subtreeIdx.size();
                subtreeIdx[s] = newIdx;
            }
            subtreeToHash[node] = subtreeIdx[s];
            if(hashToSubtrees.count(subtreeToHash[node])){
                hashToSubtrees[subtreeToHash[node]].second = node; 
            }else{
                hashToSubtrees[subtreeToHash[node]].first = node;
            }
        }
    }
    
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string, int> subtreeIdx;
        unordered_map<TreeNode*, int> subtreeToHash;
        unordered_map<int, pair<TreeNode*, TreeNode*>> hashToSubtrees;
        computeSubtreeHashes(root, subtreeIdx, subtreeToHash, hashToSubtrees);
        
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