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
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        const int N = s1.length();
        const int A = 26;

        Graph G(A);
        for(int i = 0; i < N; ++i){
            int a = s1[i] - 'a';
            int b = s2[i] - 'a';
            G[a].push_back(b);
            G[b].push_back(a);
        }

        vector<bool> vis(A, false);
        vector<int> minEq(A);
        for(int node = 0; node < A; ++node){
            if(!vis[node]){
                vector<int> ccNodes;
                dfs(node, vis, G, ccNodes);

                int minCCNode = *min_element(ccNodes.begin(), ccNodes.end());
                for(int ccNode: ccNodes){
                    minEq[ccNode] = minCCNode;
                }
            }
        }

        string minBaseStr = baseStr;
        for(int i = 0; i < (int)baseStr.length(); ++i){
            minBaseStr[i] = char(minEq[baseStr[i] - 'a'] + 'a');
        }

        return minBaseStr;
    }
};