class Solution {
private:
    struct PairHash{
        size_t operator()(const pair<int, int>& P) const{
            size_t first = P.first;
            size_t second = P.second;
            return (first | (second << 16));
        }
    };
    
public:
    int minAreaRect(vector<vector<int>>& points) {
        const int N = points.size();
        const int INF = INT_MAX;
        
        unordered_set<pair<int, int>, PairHash> pointsSet;
        for(int i = 0; i < N; ++i){
            pointsSet.emplace(points[i][0], points[i][1]);
        }
        
        int minArea = INF;
        for(int i = 0; i < N; ++i){
            for(int j = i + 1; j < N; ++j){
                int x1 = points[i][0];
                int y1 = points[i][1];
                int x2 = points[j][0];
                int y2 = points[j][1];
                if(x1 != x2 && y1 != y2){
                    if(pointsSet.count({x1, y2}) && pointsSet.count({x2, y1})){
                        int area = abs(x2 - x1) * abs(y2 - y1);
                        minArea = min(minArea, area);
                    }
                }
            }
        }
        
        if(minArea == INF){
            minArea = 0;
        }
        
        return minArea;
    }
};