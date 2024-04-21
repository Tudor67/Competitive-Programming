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
    bool isLessForReversed(const string& A, const string& B){
        const int A_LEN = A.length();
        const int B_LEN = B.length();

        for(int i = A_LEN - 1, j = B_LEN - 1; i >= 0 && j >= 0; --i, --j){
            if(A[i] < B[j]){
                return true;
            }else if(A[i] > B[j]){
                return false;
            }
        }

        return (A_LEN < B_LEN);
    }

    void dfs(TreeNode* node, string& st, string& res){
        if(node != nullptr){
            st.push_back(char(node->val + 'a'));

            if(node->left == nullptr && node->right == nullptr){
                if(res.empty() || isLessForReversed(st, res)){
                    res = st;
                }
            }

            dfs(node->left, st, res);
            dfs(node->right, st, res);

            st.pop_back();
        }
    }

public:
    string smallestFromLeaf(TreeNode* root) {
        string st;
        string res;
        dfs(root, st, res);
        return string(res.rbegin(), res.rend());
    }
};