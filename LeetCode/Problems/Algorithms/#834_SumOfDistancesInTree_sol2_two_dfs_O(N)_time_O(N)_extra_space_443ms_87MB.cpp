class Solution {
private:
    using Edge = vector<int>;
    using Graph = vector<vector<int>>;
    
    void dfs1(int prevNode, int node, const Graph& G, vector<int>& subtreeDistSum, vector<int>& subtreeNodeCount){
        for(int nextNode: G[node]){
            if(prevNode != nextNode){
                dfs1(node, nextNode, G, subtreeDistSum, subtreeNodeCount);
                subtreeDistSum[node] += subtreeDistSum[nextNode];
                subtreeDistSum[node] += subtreeNodeCount[nextNode];
                subtreeNodeCount[node] += subtreeNodeCount[nextNode];
            }
        }
        subtreeNodeCount[node] += 1;
    }
    
    void dfs2(int prevNode, int node, const Graph& G, vector<int>& subtreeDistSum, vector<int>& subtreeNodeCount, vector<int>& sumOfDistances){
        int upDistSum = sumOfDistances[prevNode] - (subtreeDistSum[node] + subtreeNodeCount[node]) + ((int)G.size() - subtreeNodeCount[node]);
        int downDistSum = subtreeDistSum[node];
        sumOfDistances[node] = upDistSum + downDistSum;
        for(int nextNode: G[node]){
            if(prevNode != nextNode){
                dfs2(node, nextNode, G, subtreeDistSum, subtreeNodeCount, sumOfDistances);
            }
        }
    }
    
public:
    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
        Graph g(N);
        for(const Edge& E: edges){
            int x = E[0];
            int y = E[1];
            g[x].push_back(y);
            g[y].push_back(x);
        }
        
        const int ROOT = 0;
        vector<int> subtreeDistSum(N, 0);
        vector<int> subtreeNodeCount(N, 0);
        dfs1(-1, ROOT, g, subtreeDistSum, subtreeNodeCount);
        
        vector<int> sumOfDistances(N, 0);
        sumOfDistances[ROOT] = subtreeDistSum[ROOT];
        for(int rootChild: g[ROOT]){
            dfs2(ROOT, rootChild, g, subtreeDistSum, subtreeNodeCount, sumOfDistances);
        }
        
        return sumOfDistances;
    }
};