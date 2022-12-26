class Solution {
private:
    using Graph = vector<vector<int>>;
    
    int areConnected(int a, int b, const Graph& G){
        return (binary_search(G[a].begin(), G[a].end(), b));
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

        // Collect odd degree nodes
        vector<int> oddDegreeNodes;
        for(int node = 1; node <= N; ++node){
            if((int)G[node].size() % 2 == 1){
                oddDegreeNodes.push_back(node);
            }
        }

        // Try to solve the odd degree nodes
        if((int)oddDegreeNodes.size() == 0){
            return true;
        }

        if((int)oddDegreeNodes.size() == 2){
            int a = oddDegreeNodes[0];
            int b = oddDegreeNodes[1];
            if(!areConnected(a, b, G)){
                return true;
            }
            for(int node = 1; node <= N; ++node){
                if(a != node && node != b){
                    if(!areConnected(a, node, G) && !areConnected(node, b, G)){
                        return true;
                    }
                }
            }
        }

        if((int)oddDegreeNodes.size() == 4){
            int a = oddDegreeNodes[0];
            int b = oddDegreeNodes[1];
            int c = oddDegreeNodes[2];
            int d = oddDegreeNodes[3];
            if((!areConnected(a, b, G) && !areConnected(c, d, G)) ||
               (!areConnected(a, c, G) && !areConnected(b, d, G)) ||
               (!areConnected(a, d, G) && !areConnected(b, c, G))){
                return true;
            }
        }

        return false;
    }
};