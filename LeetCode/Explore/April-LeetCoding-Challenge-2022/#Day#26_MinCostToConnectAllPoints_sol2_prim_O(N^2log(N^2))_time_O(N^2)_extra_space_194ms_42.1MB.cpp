class Solution {
private:
    int computeManhattanDistance(const vector<int>& A, const vector<int>& B){
        return abs(A[0] - B[0]) + abs(A[1] - B[1]);
    }
    
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        const int N = points.size();
        using Edge = pair<int, int>;
        
        priority_queue<Edge, vector<Edge>, greater<Edge>> minHeap;
        vector<bool> inMST(N, false);
        minHeap.emplace(0, 0);
        int minCost = 0;
        int edgesInMST = 0;
        while(edgesInMST < N){
            int dist = minHeap.top().first;
            int currentNode = minHeap.top().second;
            minHeap.pop();
            
            if(inMST[currentNode]){
                continue;
            }
            
            inMST[currentNode] = true;
            minCost += dist;
            edgesInMST += 1;
            
            for(int nextNode = 1; nextNode < N; ++nextNode){
                if(!inMST[nextNode]){
                    minHeap.emplace(computeManhattanDistance(points[currentNode], points[nextNode]), nextNode);
                }
            }
        }
        
        return minCost;
    }
};