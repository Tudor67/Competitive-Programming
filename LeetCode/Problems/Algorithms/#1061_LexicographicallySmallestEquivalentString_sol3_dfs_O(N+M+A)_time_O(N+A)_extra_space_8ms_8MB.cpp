class Solution {
private:
    using Graph = vector<vector<int>>;

    void dfs(int node, vector<bool>& vis, const Graph& G, vector<int>& groupNodes){
        if(vis[node]){
            return;
        }
        vis[node] = true;
        groupNodes.push_back(node);
        for(int nextNode: G[node]){
            dfs(nextNode, vis, G, groupNodes);
        }
    }

public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        const int N = s1.length();
        const int M = baseStr.length();
        const int A = 26;
        const int FIRST_CHAR = 'a';

        Graph G(A);
        for(int i = 0; i < N; ++i){
            int x = s1[i] - FIRST_CHAR;
            int y = s2[i] - FIRST_CHAR;
            G[x].push_back(y);
            G[y].push_back(x);
        }

        vector<bool> vis(A, false);
        vector<int> minCharOf(A);
        for(int node = 0; node < A; ++node){
            if(!vis[node]){
                vector<int> groupNodes;
                dfs(node, vis, G, groupNodes);

                int minChar = *min_element(groupNodes.begin(), groupNodes.end()) + FIRST_CHAR;
                for(int groupNode: groupNodes){
                    minCharOf[groupNode] = minChar;
                }
            }
        }

        string res = baseStr;
        for(int i = 0; i < M; ++i){
            res[i] = minCharOf[baseStr[i] - FIRST_CHAR];
        }

        return res;
    }
};