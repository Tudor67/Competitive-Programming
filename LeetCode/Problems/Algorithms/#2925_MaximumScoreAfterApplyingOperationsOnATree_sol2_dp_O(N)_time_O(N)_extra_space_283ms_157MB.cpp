class Solution {
private:
    using Graph = vector<vector<int>>;
    
    long long computeMinLoss(int parent, int node, const Graph& G, vector<int>& values){
        long long childrenTotalMinLoss = 0;
        for(int nextNode: G[node]){
            if(nextNode != parent){
                childrenTotalMinLoss += computeMinLoss(node, nextNode, G, values);
            }
        }
        
        if(childrenTotalMinLoss == 0){
            // current node is a leaf
            return values[node];
        }
        
        return min((long long)values[node], childrenTotalMinLoss);
    }
    
public:
    long long maximumScoreAfterOperations(vector<vector<int>>& edges, vector<int>& values) {
        const int N = edges.size() + 1;
        
        Graph G(N);
        for(const vector<int>& EDGE: edges){
            int a = EDGE[0];
            int b = EDGE[1];
            G[a].push_back(b);
            G[b].push_back(a);
        }
        
        long long totalSum = accumulate(values.begin(), values.end(), (long long)0);
        long long minLoss = computeMinLoss(-1, 0, G, values);
        
        return totalSum - minLoss;
    }
};