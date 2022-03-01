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
    int strDiff(string& maxPath, string& minPath){
        const int L = maxPath.length();
        long long diff = 0;
        for(int i = 0; i < L; ++i){
            diff = diff * 2 + (int)maxPath[i] - (int)minPath[i];
        }
        return diff;
    }
    
    void dfs(int level, TreeNode* node, string& path, vector<string>& minPathAt, vector<string>& maxPathAt, int& maxWidth){
        if(node != NULL){
            if((int)minPathAt.size() <= level){
                minPathAt.push_back(path);
            }
            if((int)maxPathAt.size() <= level){
                maxPathAt.push_back(path);
            }
            
            minPathAt[level] = min(minPathAt[level], path);
            maxPathAt[level] = max(maxPathAt[level], path);
            
            int width = 1 + strDiff(maxPathAt[level], minPathAt[level]);
            maxWidth = max(maxWidth, width);
            
            path.push_back('0');
            dfs(level + 1, node->left, path, minPathAt, maxPathAt, maxWidth);
            path.pop_back();
            
            path.push_back('1');
            dfs(level + 1, node->right, path, minPathAt, maxPathAt, maxWidth);
            path.pop_back();
        }
    }
    
public:
    int widthOfBinaryTree(TreeNode* root) {
        string path = "1";
        vector<string> minPathAt;
        vector<string> maxPathAt;
        int maxWidth = 0;
        dfs(0, root, path, minPathAt, maxPathAt, maxWidth);
        return maxWidth;
    }
};