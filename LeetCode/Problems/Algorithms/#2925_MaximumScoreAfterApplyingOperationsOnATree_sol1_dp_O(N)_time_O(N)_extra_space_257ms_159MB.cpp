class Solution {
private:
    using Graph = vector<vector<int>>;
    
    long long computeMaxScore(int parent, int node, const Graph& G,
                              vector<int>& values, vector<long long>& subtreeSum){
        subtreeSum[node] = values[node];

        long long childrenTotalScore = 0;
        for(int nextNode: G[node]){
            if(nextNode != parent){
                childrenTotalScore += computeMaxScore(node, nextNode, G, values, subtreeSum);
                subtreeSum[node] += subtreeSum[nextNode];
            }
        }

        if(subtreeSum[node] == values[node]){
            return 0;
        }
        return max(values[node] + childrenTotalScore, subtreeSum[node] - values[node]);
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
        
        vector<long long> subtreeSum(N);
        return computeMaxScore(-1, 0, G, values, subtreeSum);
    }
};