class Solution {
private:
    int computeIntersection(int a1, int a2, int b1, int b2){
        return min(a2, b2) - max(a1, b1);
    }

public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        const int N = bottomLeft.size();

        int maxSqSide = 0;
        for(int i = 0; i < N; ++i){
            for(int j = i + 1; j < N; ++j){
                int xSide = computeIntersection(bottomLeft[i][0], topRight[i][0],
                                                bottomLeft[j][0], topRight[j][0]);
                int ySide = computeIntersection(bottomLeft[i][1], topRight[i][1],
                                                bottomLeft[j][1], topRight[j][1]);
                int sqSide = min(xSide, ySide);
                maxSqSide = max(maxSqSide, sqSide);
            }
        }

        return maxSqSide * (long long)maxSqSide;
    }
};