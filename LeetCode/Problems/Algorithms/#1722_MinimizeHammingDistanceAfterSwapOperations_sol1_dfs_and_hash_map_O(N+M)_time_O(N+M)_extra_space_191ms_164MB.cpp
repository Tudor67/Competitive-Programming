class Solution {
private:
    using Graph = vector<vector<int>>;

    void dfs(int node, vector<bool>& vis, const Graph& G, vector<int>& ccNodes){
        if(vis[node]){
            return;
        }
        vis[node] = true;
        ccNodes.push_back(node);
        for(int nextNode: G[node]){
            dfs(nextNode, vis, G, ccNodes);
        }
    }

public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        const int N = source.size();

        Graph G(N);
        for(vector<int>& s: allowedSwaps){
            int a = s[0];
            int b = s[1];
            G[a].push_back(b);
            G[b].push_back(a);
        }

        int minDist = 0;
        vector<bool> vis(N, false);
        for(int srcNode = 0; srcNode < N; ++srcNode){
            if(!vis[srcNode]){
                vector<int> ccNodes;
                dfs(srcNode, vis, G, ccNodes);

                unordered_map<int, int> balance;
                for(int node: ccNodes){
                    balance[source[node]] += 1;
                    balance[target[node]] -= 1;
                }

                for(const auto& [_, bal]: balance){
                    if(bal > 0){
                        minDist += bal;
                    }
                }
            }
        }

        return minDist;
    }
};