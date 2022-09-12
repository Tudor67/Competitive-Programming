class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        const int N = points.size();
        
        int res = 0;
        unordered_map<int, int> count;
        for(int i = 0; i < N; ++i){
            count.clear();
            for(int j = 0; j < N; ++j){
                if(i != j){
                    int dx = points[i][0] - points[j][0];
                    int dy = points[i][1] - points[j][1];
                    int distance = dx * dx + dy * dy;
                    count[distance] += 1;
                }
            }
            for(const pair<int, int>& P: count){
                int distance = P.first;
                int distanceCount = P.second;
                res += distanceCount * (distanceCount - 1);
            }
        }
        
        return res;
    }
};