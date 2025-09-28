class Solution {
private:
    double computeArea(const vector<int>& A, const vector<int>& B, const vector<int>& C){
        return abs(A[0] * B[1] + B[0] * C[1] + C[0] * A[1]
                 - A[1] * B[0] - B[1] * C[0] - C[1] * A[0]) / 2.0;
    }

public:
    double largestTriangleArea(vector<vector<int>>& points) {
        const int N = points.size();

        double maxArea = 0;
        for(int i = 0; i < N; ++i){
            for(int j = i + 1; j < N; ++j){
                for(int k = j + 1; k < N; ++k){
                    double area = computeArea(points[i], points[j], points[k]);
                    maxArea = max(maxArea, area);
                }
            }
        }

        return maxArea;
    }
};