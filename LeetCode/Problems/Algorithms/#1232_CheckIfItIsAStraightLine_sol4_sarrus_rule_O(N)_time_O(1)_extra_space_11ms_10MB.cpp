class Solution {
private:
    using Point = vector<int>;

    int getOrientation(const Point& A, const Point& B, const Point& C){
        return A[0] * B[1] + B[0] * C[1] + C[0] * A[1]
             - A[0] * C[1] - B[0] * A[1] - C[0] * B[1];
    }

public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        const int N = coordinates.size();
        for(int i = 2; i < N; ++i){
            if(getOrientation(coordinates[0], coordinates[1], coordinates[i]) != 0){
                return false;
            }
        }
        return true;
    }
};