class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        const int N = points.size();

        vector<pair<int, int>> sortedPoints(N);
        for(int i = 0; i < N; ++i){
            sortedPoints[i] = {points[i][0], points[i][1]};
        }

        sort(sortedPoints.begin(), sortedPoints.end());

        int res = 1;
        int minEnd = sortedPoints[0].second;
        for(int i = 1; i < N; ++i){
            if(minEnd < sortedPoints[i].first){
                res += 1;
                minEnd = sortedPoints[i].second;
            }else{
                minEnd = min(minEnd, sortedPoints[i].second);
            }
        }

        return res;
    }
};