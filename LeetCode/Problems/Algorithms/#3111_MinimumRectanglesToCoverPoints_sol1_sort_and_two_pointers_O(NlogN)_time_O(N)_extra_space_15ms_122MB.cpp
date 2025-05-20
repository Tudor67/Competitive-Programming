class Solution {
public:
    int minRectanglesToCoverPoints(vector<vector<int>>& points, int w) {
        const int N = points.size();

        vector<int> x(N);
        for(int i = 0; i < N; ++i){
            x[i] = points[i][0];
        }

        sort(x.begin(), x.end());

        int rectangles = 1;
        int l = 0;
        for(int r = 0; r < N; ++r){
            if(x[r] - x[l] > w){
                rectangles += 1;
                l = r;
            }
        }

        return rectangles;
    }
};