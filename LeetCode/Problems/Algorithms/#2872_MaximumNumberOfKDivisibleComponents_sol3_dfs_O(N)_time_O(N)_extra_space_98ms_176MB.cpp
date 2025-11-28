class Solution {
private:
    using Tree = vector<vector<int>>;

    void dfs(int parent, int node, Tree& tree, vector<int>& values, int k, vector<int>& subtreeRem){
        subtreeRem[node] += values[node];
        subtreeRem[node] %= k;
        for(int nextNode: tree[node]){
            if(nextNode != parent){
                dfs(node, nextNode, tree, values, k, subtreeRem);
                subtreeRem[node] += subtreeRem[nextNode];
                subtreeRem[node] %= k;
            }
        }
    }

public:
    int maxKDivisibleComponents(int N, vector<vector<int>>& edges, vector<int>& values, int k) {
        Tree tree(N);
        for(vector<int>& edge: edges){
            int a = edge[0];
            int b = edge[1];
            tree[a].push_back(b);
            tree[b].push_back(a);
        }

        vector<int> subtreeRem(N);
        dfs(-1, 0, tree, values, k, subtreeRem);

        return count(subtreeRem.begin(), subtreeRem.end(), 0);
    }
};