class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        const int N = points.size();

        int minTime = 0;
        for(int i = 0; i + 1 < N; ++i){
            int dx = abs(points[i][0] - points[i + 1][0]);
            int dy = abs(points[i][1] - points[i + 1][1]);
            minTime += max(dx, dy);
        }

        return minTime;
    }
};