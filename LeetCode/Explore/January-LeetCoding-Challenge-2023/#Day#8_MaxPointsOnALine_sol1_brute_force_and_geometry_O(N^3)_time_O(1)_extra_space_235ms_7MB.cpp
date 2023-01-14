class Solution {
private:
    using Point = vector<int>;

    int getOrientation(const Point& A, const Point& B, const Point& C){
        return (A[0] * B[1] + B[0] * C[1] + C[0] * A[1] -
                A[0] * C[1] - B[0] * A[1] - C[0] * B[1]);
    }

public:
    int maxPoints(vector<Point>& points) {
        const int N = points.size();

        int res = min(2, N);
        for(int i = 0; i < N; ++i){
            for(int j = i + 1; j < N; ++j){
                int linePoints = 2;
                for(int k = j + 1; k < N; ++k){
                    if(getOrientation(points[i], points[j], points[k]) == 0){
                        linePoints += 1;
                    }
                }
                res = max(res, linePoints);
            }
        }

        return res;
    }
};