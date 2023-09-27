class Solution {
private:
    int computeDistance(const vector<int>& A, const vector<int>& B){
        return abs(A[0] - B[0]) + abs(A[1] - B[1]);
    }

public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        const int N = points.size();
        const int INF = 2e9 + 7;

        vector<int> minDist(N, INF);
        vector<bool> inMST(N, false);
        minDist[0] = 0;
        inMST[0] = true;
        int prevAddedPoint = 0;
        int mstCost = 0;

        for(int iteration = 1; iteration <= N - 1; ++iteration){
            for(int i = 0; i < N; ++i){
                minDist[i] = min(minDist[i], computeDistance(points[prevAddedPoint], points[i]));
            }

            int closestPointDist = INF;
            int closestPoint = -1;
            for(int i = 0; i < N; ++i){
                if(!inMST[i]){
                    if(closestPointDist > minDist[i]){
                        closestPointDist = minDist[i];
                        closestPoint = i;
                    }
                }
            }
            
            inMST[closestPoint] = true;
            mstCost += minDist[closestPoint];
            prevAddedPoint = closestPoint;
        }

        return mstCost;
    }
};