class Solution {
private:
    using Graph = vector<vector<int>>;
    const int INF = 1e9;

    void dfs1(int node, vector<bool>& vis, vector<bool>& isInStack, const Graph& G, bool& containsCycle){
        vis[node] = true;
        isInStack[node] = true;
        for(int nextNode: G[node]){
            if(vis[nextNode]){
                if(isInStack[nextNode]){
                    containsCycle = true;
                }
            }else{
                dfs1(nextNode, vis, isInStack, G, containsCycle);
            }
        }
        isInStack[node] = false;
    }

    void dfs2(int node, char targetColor, string& colors, const Graph& G, vector<int>& memo){
        if(memo[node] == INF){
            int maxFreq = 0;
            for(int nextNode: G[node]){
                dfs2(nextNode, targetColor, colors, G, memo);
                maxFreq = max(maxFreq, memo[nextNode]);
            }
            memo[node] = (int)(colors[node] == targetColor) + maxFreq;
        }
    }

public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        const int N = colors.size();
        const int E = edges.size();

        // Step 0: create graph G
        Graph G(N);
        for(const vector<int>& EDGE: edges){
            int a = EDGE[0];
            int b = EDGE[1];
            G[a].push_back(b);
        }

        // Step 1: check if the graph G contains at least one cycle
        vector<bool> vis(N, false);
        vector<bool> isInStack(N, false);
        bool containsCycle = false;
        for(int node = 0; node < N; ++node){
            if(!vis[node]){
                dfs1(node, vis, isInStack, G, containsCycle);
            }
        }

        if(containsCycle){
            return -1;
        }

        // Step 2: fix one targetColor and find the path with the max frequency of targetColor
        //         repeat this process for all targetColors: ['a' .. 'z'] and update the result
        int res = 0;
        vector<int> memo(N);
        for(char targetColor = 'a'; targetColor <= 'z'; ++targetColor){
            fill(memo.begin(), memo.end(), INF);
            for(int node = 0; node < N; ++node){
                dfs2(node, targetColor, colors, G, memo);
            }
            int targetColorMaxFreq = *max_element(memo.begin(), memo.end());
            res = max(res, targetColorMaxFreq);
        }

        return res;
    }
};