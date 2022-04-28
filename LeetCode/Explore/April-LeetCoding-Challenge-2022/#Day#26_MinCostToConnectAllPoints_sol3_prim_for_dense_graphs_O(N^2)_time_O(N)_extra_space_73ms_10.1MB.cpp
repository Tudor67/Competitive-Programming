class Solution {
private:
    int computeManhattanDistance(const vector<int>& A, const vector<int>& B){
        return abs(A[0] - B[0]) + abs(A[1] - B[1]);
    }
    
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        const int N = points.size();
        const int INF = 1e9;
        
        // minDist[`b`]: min distance from a node `a` to node `b`
        //               such that (inMST[`a`] == true) and (inMST[`b`] == false)
        vector<int> minDist(N, INF);
        vector<bool> inMST(N, false);
        
        int minCost = 0;
        int prevNode = 0;
        inMST[0] = true;
        for(int edgesInMST = 1; edgesInMST <= N - 1; ++edgesInMST){
            int closestNode = -1;
            int closestNodeDist = INF;
            for(int node = 0; node < N; ++node){
                if(!inMST[node]){
                    minDist[node] = min(minDist[node], computeManhattanDistance(points[prevNode], points[node]));
                    if(minDist[node] < closestNodeDist){
                        closestNodeDist = minDist[node];
                        closestNode = node;
                    }
                }
            }
            inMST[closestNode] = true;
            minCost += closestNodeDist;
            prevNode = closestNode;
        }
        
        return minCost;
    }
};