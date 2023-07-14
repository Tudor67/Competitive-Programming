class Solution {
private:
    using Graph = vector<vector<int>>;

    void dfs(int node, vector<bool>& vis, vector<bool>& isInStack, const Graph& G, bool& containsCycle){
        if(vis[node] || containsCycle){
            return;
        }
        vis[node] = true;
        isInStack[node] = true;
        for(int nextNode: G[node]){
            if(isInStack[nextNode]){
                containsCycle = true;
            }else{
                dfs(nextNode, vis, isInStack, G, containsCycle);
            }
        }
        isInStack[node] = false;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        const int N = numCourses;

        Graph G(N);
        for(const vector<int>& P: prerequisites){
            int a = P[0];
            int b = P[1];
            G[b].push_back(a);
        }

        vector<bool> vis(N, false);
        vector<bool> isInStack(N, false);
        bool containsCycle = false;
        for(int node = 0; node < N; ++node){
            dfs(node, vis, isInStack, G, containsCycle);
        }

        return !containsCycle;
    }
};