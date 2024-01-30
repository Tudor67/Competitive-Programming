class Solution {
private:
    using Graph = vector<vector<pair<char, int>>>;

    void dfs(int parent, int node, int parityMask, const Graph& G, long long& res){
        for(const pair<char, int>& P: G[node]){
            int colorIndex = P.first - 'a';
            int nextNode = P.second;
            int nextParityMask = parityMask ^ (1 << colorIndex);
            if(nextNode != parent){
                dfs(node, nextNode, nextParityMask, G, res);
                if(!(nextParityMask & (nextParityMask - 1))){
                    res += 1;
                }
            }
        }
    }

public:
    long long countPalindromePaths(vector<int>& parent, string s) {
        const int N = parent.size();

        Graph G(N);
        for(int node = 1; node < N; ++node){
            G[node].push_back({s[node], parent[node]});
            G[parent[node]].push_back({s[node], node});
        }

        long long res = 0;
        for(int startNode = 0; startNode < N; ++startNode){
            dfs(-1, startNode, 0, G, res);
        }

        return res / 2;
    }
};