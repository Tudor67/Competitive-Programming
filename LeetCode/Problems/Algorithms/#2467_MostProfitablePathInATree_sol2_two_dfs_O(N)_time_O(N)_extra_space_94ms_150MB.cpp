class Solution {
private:
    using Graph = vector<vector<int>>;

    void computeParentsAndLevels(int level, int parent, int node,
                                 vector<int>& parentOf, vector<int>& levelOf, const Graph& G){
        parentOf[node] = parent;
        levelOf[node] = level;
        for(int nextNode: G[node]){
            if(nextNode != parent){
                computeParentsAndLevels(level + 1, node, nextNode, parentOf, levelOf, G);
            }
        }
    }

    int computeMaxPoints(int parent, int node, vector<int>& remAmount, const Graph& G){
        int maxSubtreePoints = INT_MIN;
        for(int nextNode: G[node]){
            if(nextNode != parent){
                maxSubtreePoints = max(maxSubtreePoints, computeMaxPoints(node, nextNode, remAmount, G));
            }
        }
        if(maxSubtreePoints == INT_MIN){
            return remAmount[node];
        }
        return remAmount[node] + maxSubtreePoints;
    }

public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        const int E = edges.size();
        const int N = E + 1;

        // build graph G
        Graph G(N);
        for(vector<int>& edge: edges){
            int a = edge[0];
            int b = edge[1];
            G[a].push_back(b);
            G[b].push_back(a);
        }

        vector<int> parentOf(N, -1);
        vector<int> levelOf(N, -1);
        computeParentsAndLevels(1, -1, 0, parentOf, levelOf, G);

        // remove Bob's points
        vector<int> remAmount = amount;

        int currNode = bob;
        for(int i = 1; i <= levelOf[bob] / 2; ++i){
            remAmount[currNode] = 0;
            currNode = parentOf[currNode];
        }

        if(levelOf[bob] % 2 == 1){
            remAmount[currNode] = remAmount[currNode] / 2;
        }
        
        // compute Alice's points
        return computeMaxPoints(-1, 0, remAmount, G);
    }
};