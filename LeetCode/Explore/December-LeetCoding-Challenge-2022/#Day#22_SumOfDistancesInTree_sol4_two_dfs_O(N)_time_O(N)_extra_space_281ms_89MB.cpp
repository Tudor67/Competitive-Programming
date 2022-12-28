class Solution {
private:
    using Graph = vector<vector<int>>;

    void postorder(int parentNode, int node, const Graph& G, vector<int>& subtreeNodes, vector<int>& subtreeDistSum){
        subtreeNodes[node] = 1;
        for(int child: G[node]){
            if(child != parentNode){
                postorder(node, child, G, subtreeNodes, subtreeDistSum);
                subtreeNodes[node] += subtreeNodes[child];
                subtreeDistSum[node] += (subtreeDistSum[child] + subtreeNodes[child]);
            }
        }
    }

    void preorder(int parentNode, int node, const Graph& G, vector<int>& subtreeNodes, vector<int>& subtreeDistSum,
                  vector<int>& totalDistSum){
        const int N = G.size();
        for(int child: G[node]){
            if(child != parentNode){
                totalDistSum[child] = subtreeDistSum[child] +
                                      (totalDistSum[node] - subtreeDistSum[child] - subtreeNodes[child]) +
                                      (N - subtreeNodes[child]);
                preorder(node, child, G, subtreeNodes, subtreeDistSum, totalDistSum);
            }
        }
    }

public:
    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
        Graph G(N);
        for(const vector<int>& E: edges){
            int a = E[0];
            int b = E[1];
            G[a].push_back(b);
            G[b].push_back(a);
        }

        vector<int> subtreeNodes(N);
        vector<int> subtreeDistSum(N);
        postorder(-1, 0, G, subtreeNodes, subtreeDistSum);

        vector<int> totalDistSum(N);
        totalDistSum[0] = subtreeDistSum[0];
        preorder(-1, 0, G, subtreeNodes, subtreeDistSum, totalDistSum);

        return totalDistSum;
    }
};