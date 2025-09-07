class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        const int N = points.size();

        vector<vector<int>> sortedPoints = points;
        sort(sortedPoints.begin(), sortedPoints.end(),
             [](const vector<int>& A, const vector<int>& B){
                return (pair<int, int>{A[0], -A[1]} <
                        pair<int, int>{B[0], -B[1]});
             });

        int goodPairs = 0;
        for(int i = 0; i < N; ++i){
            int maxY = -1;
            for(int j = i + 1; j < N; ++j){
                if(sortedPoints[i][1] >= sortedPoints[j][1] && maxY < sortedPoints[j][1]){
                    goodPairs += 1;
                    maxY = sortedPoints[j][1];
                }
            }
        }

        return goodPairs;
    }
};