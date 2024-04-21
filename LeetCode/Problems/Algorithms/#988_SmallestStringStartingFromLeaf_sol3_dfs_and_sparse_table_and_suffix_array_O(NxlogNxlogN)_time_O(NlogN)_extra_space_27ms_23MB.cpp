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
    void dfs(TreeNode* root, int parent, vector<char>& chars, vector<int>& parentOf, vector<int>& leafNodes){
        if(root == nullptr){
            return;
        }

        int node = chars.size();
        chars.push_back(char(root->val + 'a'));
        parentOf.push_back(parent);

        if(root->left == nullptr && root->right == nullptr){
            leafNodes.push_back(node);
        }

        dfs(root->left, node, chars, parentOf, leafNodes);
        dfs(root->right, node, chars, parentOf, leafNodes);
    }

public:
    string smallestFromLeaf(TreeNode* root) {
        // Step 1: dfs
        vector<char> chars;
        vector<int> parentOf;
        vector<int> leafNodes;
        dfs(root, -1, chars, parentOf, leafNodes);

        // Step 2: sparse table p
        const int N = chars.size();
        const int LOG_N = ceil(log2(N));
        vector<vector<int>> p(LOG_N + 1, vector<int>(N, -1));
        p[0] = parentOf;

        for(int k = 1; k <= LOG_N; ++k){
            for(int i = 0; i < N; ++i){
                if(p[k - 1][i] != -1){
                    p[k][i] = p[k - 1][p[k - 1][i]];
                }
            }
        }

        // Step 3: suffix array
        vector<vector<int>> c(LOG_N + 1, vector<int>(N));
        for(int i = 0; i < N; ++i){
            c[0][i] = chars[i] - 'a';
        }

        vector<pair<pair<int, int>, int>> v(N);
        for(int k = 1; k <= LOG_N; ++k){
            for(int i = 0; i < N; ++i){
                int l = c[k - 1][i];
                int r = (p[k - 1][i] != -1 ? c[k - 1][p[k - 1][i]] : -1);
                v[i].first = {l, r};
                v[i].second = i;
            }

            sort(v.begin(), v.end());

            int classID = 0;
            for(int i = 0; i < N; ++i){
                if(i > 0 && v[i - 1].first != v[i].first){
                    classID += 1;
                }
                int index = v[i].second;
                c[k][index] = classID;
            }
        }

        int bestLeafNode = leafNodes[0];
        for(int leafNode: leafNodes){
            if(c.back()[leafNode] < c.back()[bestLeafNode]){
                bestLeafNode = leafNode;
            }
        }
        
        string res;
        for(int node = bestLeafNode; node != -1; node = parentOf[node]){
            res += chars[node];
        }

        return res;
    }
};