class Solution {
private:
    using Point = vector<int>;
    
    int computeOrientation(const Point& A, const Point& B, const Point& C){
        return A[0] * B[1] + B[0] * C[1] + C[0] * A[1]
             - A[1] * B[0] - B[1] * C[0] - C[1] * A[0];
    }
    
    void addBoundaryPoints(vector<Point>& POINTS, vector<Point>& boundaryPoints){
        for(const Point& P: POINTS){
            while((int)boundaryPoints.size() >= 2 &&
                  computeOrientation(boundaryPoints[boundaryPoints.size() - 2], boundaryPoints[boundaryPoints.size() - 1], P) < 0){
                boundaryPoints.pop_back();
            }
            boundaryPoints.push_back(P);
        }
    }
    
public:
    vector<vector<int>> outerTrees(vector<Point>& points) {
        const int N = points.size();
        
        // Andrew's monotone chain algorithm
        vector<Point> convexHullPoints;
        sort(points.begin(), points.end());
        addBoundaryPoints(points, convexHullPoints);
        
        if((int)convexHullPoints.size() < N){
            reverse(points.begin(), points.end());
            convexHullPoints.pop_back();
            addBoundaryPoints(points, convexHullPoints);
            convexHullPoints.pop_back();
        }
        
        return convexHullPoints;
    }
};