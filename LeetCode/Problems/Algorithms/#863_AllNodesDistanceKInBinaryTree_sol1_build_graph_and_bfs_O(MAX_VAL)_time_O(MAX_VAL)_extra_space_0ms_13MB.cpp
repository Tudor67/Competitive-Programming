/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    using Graph = vector<vector<int>>;

    void buildGraph(TreeNode* root, Graph& G){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();

            G.resize(max((int)G.size(), node->val + 1));

            for(TreeNode* nextNode: {node->left, node->right}){
                if(nextNode != nullptr){
                    G.resize(max((int)G.size(), nextNode->val + 1));
                    G[node->val].push_back(nextNode->val);
                    G[nextNode->val].push_back(node->val);
                    q.push(nextNode);
                }
            }
        }
    }

    void collectNodesAtDistK(int srcNode, const Graph& G, int k, vector<int>& res){
        const int N = G.size();

        vector<bool> vis(N + 1, false);
        queue<int> q;
        q.push(srcNode);
        vis[srcNode] = true;

        while(!q.empty() && k >= 1){
            k -= 1;
            for(int i = q.size(); i >= 1; --i){
                int node = q.front();
                q.pop();

                for(int nextNode: G[node]){
                    if(!vis[nextNode]){
                        vis[nextNode] = true;
                        q.push(nextNode);
                    }
                }
            }
        }

        res.resize(q.size());
        for(int i = 0; i < (int)res.size(); ++i){
            res[i] = q.front();
            q.pop();
        }
    }

public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        Graph G;
        buildGraph(root, G);

        vector<int> res;
        collectNodesAtDistK(target->val, G, k, res);

        return res;
    }
};