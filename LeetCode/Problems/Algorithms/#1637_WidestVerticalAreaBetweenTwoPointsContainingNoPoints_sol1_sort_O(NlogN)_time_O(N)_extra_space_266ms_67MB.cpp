class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        const int N = points.size();

        vector<int> x(N);
        for(int i = 0; i < N; ++i){
            x[i] = points[i][0];
        }

        sort(x.begin(), x.end());

        int maxWidth = 0;
        for(int i = 1; i < N; ++i){
            maxWidth = max(maxWidth, x[i] - x[i - 1]);
        }
        
        return maxWidth;
    }
};