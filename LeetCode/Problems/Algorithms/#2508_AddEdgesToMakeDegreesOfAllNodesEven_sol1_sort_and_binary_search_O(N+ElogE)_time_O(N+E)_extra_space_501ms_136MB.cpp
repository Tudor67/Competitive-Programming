class Solution {
private:
    using Graph = vector<vector<int>>;
    const int INF = 1e9;
    
    int computeCost(int a, int b, const Graph& G, vector<int>& evenDegreeNodes){
        // Add one edge: (a, b)
        if(!binary_search(G[a].begin(), G[a].end(), b)){
            return 1;
        }

        // Add two edges: (a, e) and (e, b)
        for(int e: evenDegreeNodes){
            if(!binary_search(G[a].begin(), G[a].end(), e) &&
               !binary_search(G[b].begin(), G[b].end(), e)){
                return 2;
            }
        }

        return INF;
    }

public:
    bool isPossible(int N, vector<vector<int>>& edges) {
        // Graph G
        Graph G(N + 1);
        for(const vector<int>& E: edges){
            int a = E[0];
            int b = E[1];
            G[a].push_back(b);
            G[b].push_back(a);
        }

        // Sort the neighbors of each node
        for(int node = 1; node <= N; ++node){
            sort(G[node].begin(), G[node].end());
        }
        
        // Collect even and odd degree nodes
        vector<int> evenDegreeNodes;
        vector<int> oddDegreeNodes;
        for(int node = 1; node <= N; ++node){
            if((int)G[node].size() % 2 == 0){
                evenDegreeNodes.push_back(node);
            }else{
                oddDegreeNodes.push_back(node);
            }
        }

        // Try to solve the odd degree nodes
        if((int)oddDegreeNodes.size() == 0){
            return true;
        }

        if((int)oddDegreeNodes.size() == 2){
            if(computeCost(oddDegreeNodes[0], oddDegreeNodes[1], G, evenDegreeNodes) <= 2){
                return true;
            }
        }

        if((int)oddDegreeNodes.size() == 4){
            if(computeCost(oddDegreeNodes[0], oddDegreeNodes[1], G, evenDegreeNodes) +
               computeCost(oddDegreeNodes[2], oddDegreeNodes[3], G, evenDegreeNodes) <= 2){
                return true;
            }
            if(computeCost(oddDegreeNodes[0], oddDegreeNodes[2], G, evenDegreeNodes) +
               computeCost(oddDegreeNodes[1], oddDegreeNodes[3], G, evenDegreeNodes) <= 2){
                return true;
            }
            if(computeCost(oddDegreeNodes[0], oddDegreeNodes[3], G, evenDegreeNodes) +
               computeCost(oddDegreeNodes[1], oddDegreeNodes[2], G, evenDegreeNodes) <= 2){
                return true;
            }
        }

        return false;
    }
};