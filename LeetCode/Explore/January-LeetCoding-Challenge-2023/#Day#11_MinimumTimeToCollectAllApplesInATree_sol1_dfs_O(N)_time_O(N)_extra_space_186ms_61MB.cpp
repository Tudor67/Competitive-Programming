class Solution {
private:
    using Graph = vector<vector<int>>;

    void dfs(int parentNode, int node, vector<bool>& hasApple, vector<int>& minTime, const Graph& G){
        for(int child: G[node]){
            if(child != parentNode){
                dfs(node, child, hasApple, minTime, G);
                if(hasApple[child] || minTime[child] >= 2){
                    minTime[node] += (minTime[child] + 2);
                }
            }
        }
    }

public:
    int minTime(int N, vector<vector<int>>& edges, vector<bool>& hasApple) {
        Graph G(N);
        for(const vector<int>& E: edges){
            int a = E[0];
            int b = E[1];
            G[a].push_back(b);
            G[b].push_back(a);
        }

        vector<int> minTime(N);
        dfs(-1, 0, hasApple, minTime, G);

        return minTime[0];
    }
};