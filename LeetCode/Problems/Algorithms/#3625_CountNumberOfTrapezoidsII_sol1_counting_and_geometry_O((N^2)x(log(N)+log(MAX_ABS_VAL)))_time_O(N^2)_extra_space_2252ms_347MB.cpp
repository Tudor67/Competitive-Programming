class Solution {
private:
    template<typename T>
    long long getContrib(T& mp){
        long long contrib = 0;
        for(auto& [_, c]: mp){
            contrib += c * (long long)(c - 1) / 2;
        }
        return contrib;
    }

public:
    int countTrapezoids(vector<vector<int>>& points) {
        const int N = points.size();

        map<pair<int, int>, int> slopes;
        map<tuple<int, int, int>, int> lines;
        map<pair<int, int>, int> mids;
        map<tuple<int, int, int, int>, int> midLines;

        for(int i = 0; i < N; ++i){
            for(int j = i + 1; j < N; ++j){
                const vector<int>& A = points[i];
                const vector<int>& B = points[j];

                int dx = A[0] - B[0];
                int dy = A[1] - B[1];

                int g = gcd(dx, dy);
                dx /= g;
                dy /= g;
                if(dx < 0 || (dx == 0 && dy < 0)){
                    dx = -dx;
                    dy = -dy;
                }

                int intercept = dx * A[1] - dy * A[0];

                slopes[{dx, dy}] += 1;
                lines[{dx, dy, intercept}] += 1;
                mids[{A[0] + B[0], A[1] + B[1]}] += 1;
                midLines[{A[0] + B[0], A[1] + B[1], dx, dy}] += 1;
            }
        }

        return getContrib(slopes) - getContrib(lines)
               -
               (getContrib(mids) - getContrib(midLines));
    }
};