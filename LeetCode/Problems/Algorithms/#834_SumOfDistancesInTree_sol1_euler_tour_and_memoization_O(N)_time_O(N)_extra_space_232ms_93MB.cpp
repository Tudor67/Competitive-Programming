class Solution {
private:
    using Edge = vector<int>;
    using Graph = vector<vector<int>>;
    
    void eulerTour(int prevNode, int node, const Graph& G, vector<int>& eulerTourNodes){
        eulerTourNodes.push_back(node);
        for(int nextNode: G[node]){
            if(prevNode != nextNode){
                eulerTour(node, nextNode, G, eulerTourNodes);
                eulerTourNodes.push_back(node);
            }
        }
    }
    
    pair<int, int> solve(int prevNode, int node, const Graph& G, vector<pair<int, int>>& memo){
        int subtreeDistSum = 0;
        int subtreeNodeCount = 1;
        if(memo[node].first != -1){
            return memo[node];
        }
        for(int nextNode: G[node]){
            if(prevNode != nextNode){
                pair<int, int> subtreeP = solve(node, nextNode, G, memo);
                subtreeDistSum += subtreeP.first;
                subtreeDistSum += subtreeP.second;
                subtreeNodeCount += subtreeP.second;
            }
        }
        memo[node] = {subtreeDistSum, subtreeNodeCount};
        return {subtreeDistSum, subtreeNodeCount};
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
        
        vector<int> eulerTourNodes;
        eulerTour(-1, 0, g, eulerTourNodes);
        
        vector<int> sumOfDistances(N, 0);
        vector<pair<int, int>> memo(N, {-1, -1});
        for(int i = 0; i < (int)eulerTourNodes.size(); ++i){
            int node = eulerTourNodes[i];
            memo[node] = {-1, -1};
            if(sumOfDistances[node] == 0){
                sumOfDistances[node] = solve(-1, node, g, memo).first;
            }
            memo[node] = {-1, -1};
        }
        
        return sumOfDistances;
    }
};