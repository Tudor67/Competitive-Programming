class Solution {
private:
    void dfs(int node, int level, vector<int>& levelOf, vector<bool>& isInStack, vector<int>& edges, int& res){
        levelOf[node] = level;
        isInStack[node] = true;
        
        int nextNode = edges[node];
        if(nextNode != -1){
            if(levelOf[nextNode] == -1){
                dfs(nextNode, level + 1, levelOf, isInStack, edges, res);
            }else if(isInStack[nextNode]){
                res = max(res, levelOf[node] - levelOf[nextNode] + 1);
            }
        }

        isInStack[node] = false;
    }

public:
    int longestCycle(vector<int>& edges) {
        const int N = edges.size();

        int res = -1;
        vector<int> levelOf(N, -1);
        vector<bool> isInStack(N, false);
        for(int node = 0; node < N; ++node){
            if(levelOf[node] == -1){
                dfs(node, 0, levelOf, isInStack, edges, res);
            }
        }

        return res;
    }
};