class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        const int N = points.size();

        vector<vector<int>> sortedPoints = points;
        sort(sortedPoints.begin(), sortedPoints.end(),
             [](const vector<int>& A, const vector<int>& B){
                return (A[0] < B[0]) || (A[0] == B[0] && A[1] > B[1]);
             });

        int goodPairs = 0;
        for(int i = 0; i < N; ++i){
            int maxY = INT_MIN;
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