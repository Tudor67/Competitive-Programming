class Solution {
private:
    using Graph = vector<vector<int>>;
    const int INF = 1e9;

    void dfs(int node, vector<bool>& isInStack, vector<int>& maxFreqOfTargetColor, bool& containsCycle,
             char targetColor, string& colors, const Graph& G){
        if(maxFreqOfTargetColor[node] != -INF){
            return;
        }

        isInStack[node] = true;
        maxFreqOfTargetColor[node] = 0;
        int maxChildFreq = 0;

        for(int nextNode: G[node]){
            if(isInStack[nextNode]){
                containsCycle = true;
            }else{
                dfs(nextNode, isInStack, maxFreqOfTargetColor, containsCycle, targetColor, colors, G);
                maxChildFreq = max(maxChildFreq, maxFreqOfTargetColor[nextNode]);
            }
        }
        
        maxFreqOfTargetColor[node] = (int)(colors[node] == targetColor) + maxChildFreq;
        isInStack[node] = false;
    }

public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        const int N = colors.size();
        const int E = edges.size();

        Graph G(N);
        for(vector<int>& edge: edges){
            int a = edge[0];
            int b = edge[1];
            G[a].push_back(b);
        }

        int maxColorValue = 0;
        bool containsCycle = false;
        vector<bool> isInStack(N, false);
        vector<int> maxFreqOfTargetColor(N);

        for(char targetColor = 'a'; targetColor <= 'z' && !containsCycle; ++targetColor){
            fill(maxFreqOfTargetColor.begin(), maxFreqOfTargetColor.end(), -INF);
            for(int startNode = 0; startNode < N; ++startNode){
                if(maxFreqOfTargetColor[startNode] == -INF){
                    dfs(startNode, isInStack, maxFreqOfTargetColor, containsCycle, targetColor, colors, G);
                    maxColorValue = max(maxColorValue, maxFreqOfTargetColor[startNode]);
                }
            }
        }

        if(containsCycle){
            maxColorValue = -1;
        }

        return maxColorValue;
    }
};