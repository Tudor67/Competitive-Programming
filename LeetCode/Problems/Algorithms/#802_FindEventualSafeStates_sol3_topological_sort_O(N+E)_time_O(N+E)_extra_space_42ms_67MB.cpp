class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        const int N = graph.size();

        vector<vector<int>> transposedGraph(N);
        vector<int> inDegree(N);
        for(int node = 0; node < N; ++node){
            for(int nextNode: graph[node]){
                transposedGraph[nextNode].push_back(node);
                inDegree[node] += 1;
            }
        }

        queue<int> q;
        for(int node = 0; node < N; ++node){
            if(inDegree[node] == 0){
                q.push(node);
            }
        }

        vector<bool> isSafe(N, false);
        while(!q.empty()){
            int node = q.front();
            q.pop();

            isSafe[node] = true;

            for(int nextNode: transposedGraph[node]){
                inDegree[nextNode] -= 1;
                if(inDegree[nextNode] == 0){
                    q.push(nextNode);
                }
            }
        }

        vector<int> safeNodes;
        for(int node = 0; node < N; ++node){
            if(isSafe[node]){
                safeNodes.push_back(node);
            }
        }

        return safeNodes;
    }
};