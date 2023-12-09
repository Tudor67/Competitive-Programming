class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        const int N = points.size();

        int totalTime = 0;
        for(int i = 1; i < N; ++i){
            int dx = abs(points[i - 1][0] - points[i][0]);
            int dy = abs(points[i - 1][1] - points[i][1]);
            totalTime += max(dx, dy);
        }

        return totalTime;
    }
};