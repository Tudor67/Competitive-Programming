class Solution {
private:
    double getSquaredDist(const vector<int>& A, const vector<int>& B){
        double dx = A[0] - B[0];
        double dy = A[1] - B[1];
        return dx * dx + dy * dy;
    }

    double getDist(const vector<int>& A, const vector<int>& B){
        return sqrt(getSquaredDist(A, B));
    }
    
public:
    double minAreaFreeRect(vector<vector<int>>& points) {
        const int N = points.size();
        const double INF = LLONG_MAX / 10;
        
        set<pair<int, int>> pointsSet;
        for(int i = 0; i < N; ++i){
            pointsSet.emplace(points[i][0], points[i][1]);
        }
        
        double minArea = INF;
        for(int i = 0; i < N; ++i){
            for(int j = 0; j < N; ++j){
                for(int l = 0; l < N; ++l){
                    if(i == j || i == l || j == l){
                        continue;
                    }
                    if(getSquaredDist(points[l], points[i]) + getSquaredDist(points[i], points[j]) ==
                       getSquaredDist(points[j], points[l])){
                        pair<int, int> P = {points[l][0] + points[j][0] - points[i][0],
                                            points[l][1] + points[j][1] - points[i][1]};
                        if(pointsSet.count(P)){
                            double area = getDist(points[i], points[j]) * getDist(points[l], points[i]);
                            minArea = min(minArea, area);
                        }
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