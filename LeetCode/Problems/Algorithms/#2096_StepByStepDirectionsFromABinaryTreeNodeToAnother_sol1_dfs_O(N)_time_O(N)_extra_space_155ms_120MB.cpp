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
    void findPath(TreeNode* node, int targetValue, string& currentPath, string& targetPath){
        if(node == nullptr){
            // stop
        }else if(node->val == targetValue){
            targetPath = currentPath;
        }else if(targetPath.empty()){
            currentPath.push_back('L');
            findPath(node->left, targetValue, currentPath, targetPath);
            currentPath.pop_back();

            currentPath.push_back('R');
            findPath(node->right, targetValue, currentPath, targetPath);
            currentPath.pop_back();
        }
    }

public:
    string getDirections(TreeNode* root, int startValue, int destValue) {
        string currentPath;

        string pathToStart;
        findPath(root, startValue, currentPath, pathToStart);

        string pathToDest;
        findPath(root, destValue, currentPath, pathToDest);

        int i = 0;
        while(i < (int)min(pathToStart.length(), pathToDest.length()) && pathToStart[i] == pathToDest[i]){
            i += 1;
        }

        string shortestPath;
        shortestPath.append((int)pathToStart.length() - i, 'U');
        shortestPath.append(pathToDest.begin() + i, pathToDest.end());

        return shortestPath;
    }
};