class Solution {
private:
    using Point = vector<int>;

    double getSlope(const Point& A, const Point& B){
        double dx = A[0] - B[0];
        double dy = A[1] - B[1];
        double slope = (dx == 0 ? LLONG_MAX : dy / dx);
        return slope;
    }

public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        const int N = coordinates.size();

        double targetSlope = getSlope(coordinates[0], coordinates[1]);
        for(int i = 2; i < N; ++i){
            if(getSlope(coordinates[0], coordinates[i]) != targetSlope){
                return false;
            }
        }

        return true;
    }
};