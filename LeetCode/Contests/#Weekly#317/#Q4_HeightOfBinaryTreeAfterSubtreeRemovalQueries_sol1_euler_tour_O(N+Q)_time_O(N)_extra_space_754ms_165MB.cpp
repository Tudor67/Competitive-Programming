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
    void dfs(TreeNode* root, int height, vector<int>& eulerValues, vector<int>& eulerHeights){
        if(root != nullptr){
            eulerValues.push_back(root->val);
            eulerHeights.push_back(height);
            
            for(TreeNode* child: {root->left, root->right}){
                dfs(child, height + 1, eulerValues, eulerHeights);
                
                if(eulerValues.back() != root->val){
                    eulerValues.push_back(root->val);
                    eulerHeights.push_back(height);
                }
            }
        }
    }
    
public:
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        // euler traversal
        vector<int> eulerValues;
        vector<int> eulerHeights;
        dfs(root, 0, eulerValues, eulerHeights);
        
        // prefix and suffix max of euler heights
        const int E = eulerValues.size();
        vector<int> prefMaxHeight(E);
        prefMaxHeight[0] = eulerHeights[0];
        for(int i = 1; i < E; ++i){
            prefMaxHeight[i] = max(prefMaxHeight[i - 1], eulerHeights[i]);
        }
        
        vector<int> suffMaxHeight(E);
        suffMaxHeight[0] = eulerHeights[E - 1];
        for(int i = E - 2; i >= 0; --i){
            suffMaxHeight[i] = max(eulerHeights[i], suffMaxHeight[i + 1]);
        }
        
        // first and last pos of a value in euler values
        int maxVal = *max_element(eulerValues.begin(), eulerValues.end());
        vector<int> firstPosOf(maxVal + 1, E);
        vector<int> lastPosOf(maxVal + 1, 0);
        for(int i = 0; i < E; ++i){
            firstPosOf[eulerValues[i]] = min(firstPosOf[eulerValues[i]], i);
            lastPosOf[eulerValues[i]] = max(lastPosOf[eulerValues[i]], i);
        }
        
        // queries
        const int Q = queries.size();
        vector<int> res(Q);
        for(int i = 0; i < Q; ++i){
            res[i] = max(prefMaxHeight[firstPosOf[queries[i]] - 1],
                         suffMaxHeight[lastPosOf[queries[i]] + 1]);
        }
        
        return res;
    }
};