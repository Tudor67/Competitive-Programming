class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        const int N = points.size();

        int res = min(2, N);
        unordered_map<long double, int> count;
        for(int i = 0; i < N; ++i){
            count.clear();
            for(int j = 0; j < N; ++j){
                if(i != j){
                    long double dx = points[i][0] - points[j][0];
                    long double dy = points[i][1] - points[j][1];
                    long double slope = (dy == 0 ? INT_MIN : dx / dy);
                    count[slope] += 1;
                }
            }

            for(const pair<long double, int>& P: count){
                int linePoints = 1 + P.second;
                res = max(res, linePoints);
            }
        }

        return res;
    }
};