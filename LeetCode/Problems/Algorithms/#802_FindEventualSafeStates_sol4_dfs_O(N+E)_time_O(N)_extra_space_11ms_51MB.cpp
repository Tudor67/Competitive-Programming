class Solution {
private:
    bool isSafeNodeCheck(int node, vector<vector<int>>& graph,
                         vector<bool>& isVisited, vector<bool>& isInStack, vector<bool>& isSafe){
        if(isVisited[node]){
            if(isInStack[node]){
                isSafe[node] = false;
            }
            return isSafe[node];
        }

        isVisited[node] = true;
        isInStack[node] = true;
        isSafe[node] = true;
        for(int nextNode: graph[node]){
            if(!isSafeNodeCheck(nextNode, graph, isVisited, isInStack, isSafe)){
                isSafe[node] = false;
                break;
            }
        }

        isInStack[node] = false;

        return isSafe[node];
    }

public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        const int N = graph.size();

        vector<int> safeNodes;

        vector<bool> isVisited(N, false);
        vector<bool> isInStack(N, false);
        vector<bool> isSafe(N, false);
        for(int node = 0; node < N; ++node){
            if(isSafeNodeCheck(node, graph, isVisited, isInStack, isSafe)){
                safeNodes.push_back(node);
            }
        }

        return safeNodes;
    }
};