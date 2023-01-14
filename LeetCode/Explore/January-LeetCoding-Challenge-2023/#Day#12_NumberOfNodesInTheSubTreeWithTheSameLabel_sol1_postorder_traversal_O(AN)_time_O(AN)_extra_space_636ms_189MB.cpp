class Solution {
private:
    using Graph = vector<vector<int>>;
    const int A = 26;
    const int FIRST_CHAR = 'a';

    void dfs(int parentNode, int node, string& labels, const Graph& G, vector<vector<int>>& count){
        count[labels[node] - FIRST_CHAR][node] = 1;
        for(int child: G[node]){
            if(child != parentNode){
                dfs(node, child, labels, G, count);
                for(char c = FIRST_CHAR; c < FIRST_CHAR + A; ++c){
                    count[c - FIRST_CHAR][node] += count[c - FIRST_CHAR][child];
                }
            }
        }
    }

public:
    vector<int> countSubTrees(int N, vector<vector<int>>& edges, string labels) {
        Graph G(N);
        for(const vector<int>& E: edges){
            int a = E[0];
            int b = E[1];
            G[a].push_back(b);
            G[b].push_back(a);
        }

        vector<vector<int>> count(A, vector<int>(N));
        dfs(-1, 0, labels, G, count);

        vector<int> res(N);
        for(int node = 0; node < N; ++node){
            res[node] = count[labels[node] - FIRST_CHAR][node];
        }

        return res;
    }
};