class Solution {
private:
    double getDist(const vector<int>& A, const vector<int>& B){
        double dx = A[0] - B[0];
        double dy = A[1] - B[1];
        return sqrt(dx * dx + dy * dy);
    }
    
public:
    double minAreaFreeRect(vector<vector<int>>& points) {
        const int N = points.size();
        const double INF = LLONG_MAX / 10;
        
        map<tuple<double, double, double>, vector<pair<int, int>>> diagonalsWithCenterAndLength;
        for(int i = 0; i < N; ++i){
            for(int j = i + 1; j < N; ++j){
                double centerX = (points[i][0] + points[j][0]) / 2.0;
                double centerY = (points[i][1] + points[j][1]) / 2.0;
                double diagonalLength = getDist(points[i], points[j]);
                diagonalsWithCenterAndLength[{centerX, centerY, diagonalLength}].push_back({i, j});
            }
        }
        
        double minArea = INF;
        for(pair<const tuple<double, double, double>, vector<pair<int, int>>>& P: diagonalsWithCenterAndLength){
            vector<pair<int, int>>& d = P.second;
            for(int i = 0; i < (int)d.size(); ++i){
                for(int j = i + 1; j < (int)d.size(); ++j){
                    const vector<int>& A = points[d[i].first];
                    const vector<int>& C = points[d[i].second];
                    const vector<int>& B = points[d[j].first];
                    const vector<int>& D = points[d[j].second];
                    double area = getDist(A, B) * getDist(B, C);
                    minArea = min(minArea, area);
                }
            }
        }
        
        if(minArea == INF){
            minArea = 0;
        }
        
        return minArea;
    }
};