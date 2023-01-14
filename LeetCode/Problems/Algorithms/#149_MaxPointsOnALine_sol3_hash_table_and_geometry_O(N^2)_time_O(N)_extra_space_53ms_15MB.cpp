class Solution {
private:
    int sign(int num){
        if(num < 0){
            return -1;
        }else if(num > 0){
            return 1;
        }
        return 0;
    }

    struct TupleHash{
        size_t operator()(const tuple<int, int, int>& T) const{
            size_t signVal = get<0>(T) + 1;
            size_t dxVal = get<1>(T);
            size_t dyVal = get<2>(T);
            return (signVal) | (dxVal << 2) | (dyVal << 17);
        }
    };

public:
    int maxPoints(vector<vector<int>>& points) {
        const int N = points.size();

        int res = min(2, N);
        unordered_map<tuple<int, int, int>, int, TupleHash> count;
        for(int i = 0; i < N; ++i){
            count.clear();
            for(int j = 0; j < N; ++j){
                if(i != j){
                    int dx = points[i][0] - points[j][0];
                    int dy = points[i][1] - points[j][1];
                    tuple<int, int, int> slope = {INT_MIN, INT_MIN, INT_MIN};
                    if(dy != 0){
                        int gcdVal = gcd(abs(dx), abs(dy));
                        dx /= gcdVal;
                        dy /= gcdVal;
                        slope = {sign(dx) * sign(dy), abs(dx), abs(dy)};
                    }
                    count[slope] += 1;
                }
            }

            for(const pair<tuple<int, int, int>, int>& P: count){
                int linePoints = 1 + P.second;
                res = max(res, linePoints);
            }
        }

        return res;
    }
};