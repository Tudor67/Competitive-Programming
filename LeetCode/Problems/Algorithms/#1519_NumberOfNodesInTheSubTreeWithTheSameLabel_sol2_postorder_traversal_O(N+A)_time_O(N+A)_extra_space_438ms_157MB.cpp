class Solution {
private:
    using Graph = vector<vector<int>>;
    const int A = 26;
    const int FIRST_CHAR = 'a';

    void dfs(int parentNode, int node, string& labels, const Graph& G, vector<int>& count, vector<int>& res){
        count[labels[node] - FIRST_CHAR] += 1;

        int inCount = count[labels[node] - FIRST_CHAR];
        for(int child: G[node]){
            if(child != parentNode){
                dfs(node, child, labels, G, count, res);
            }
        }
        int outCount = count[labels[node] - FIRST_CHAR];

        res[node] = outCount - inCount + 1;
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

        vector<int> count(A);
        vector<int> res(N);
        dfs(-1, 0, labels, G, count, res);

        return res;
    }
};