class Solution {
private:
    using Point = vector<int>;

    int getXDelta(const Point& A, const Point& B){
        return A[0] - B[0];
    }

    int getYDelta(const Point& A, const Point& B){
        return A[1] - B[1];
    }

public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        const int N = coordinates.size();

        int dx01 = getXDelta(coordinates[0], coordinates[1]);
        int dy01 = getYDelta(coordinates[0], coordinates[1]);
        for(int i = 2; i < N; ++i){
            int dx0i = getXDelta(coordinates[0], coordinates[i]);
            int dy0i = getYDelta(coordinates[0], coordinates[i]);
            if(dy01 * dx0i != dy0i * dx01){
                return false;
            }
        }

        return true;
    }
};