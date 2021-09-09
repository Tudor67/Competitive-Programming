class Solution {
private:
    using Point = vector<int>;
    
    int computeOrientation(const Point& A, const Point& B, const Point& C){
        return A[0] * B[1] + B[0] * C[1] + C[0] * A[1]
             - A[1] * B[0] - B[1] * C[0] - C[1] * A[0];
    }
    
    bool isBetween(const Point& A, const Point& B, const Point& C){
        return min(A[0], B[0]) <= C[0] && C[0] <= max(A[0], B[0]) &&
               min(A[1], B[1]) <= C[1] && C[1] <= max(A[1], B[1]);
    }
    
public:
    vector<Point> outerTrees(vector<Point>& points) {
        const int N = points.size();
        
        // Jarvis algorithm
        int minPointIdx = 0;
        for(int i = 0; i < N; ++i){
            if(points[i] < points[minPointIdx]){
                minPointIdx = i;
            }
        }
        
        vector<Point> convexHullPoints = {points[minPointIdx]};
        int currentPointIdx = minPointIdx;
        while((int)convexHullPoints.size() < N){
            int nextPointIdx = (currentPointIdx + 1) % N;
            for(int i = 0; i < N; ++i){
                if(computeOrientation(points[currentPointIdx], points[nextPointIdx], points[i]) < 0){
                    nextPointIdx = i;
                }
            }
            for(int i = 0; i < N; ++i){
                if(i != currentPointIdx && i != nextPointIdx &&
                   computeOrientation(points[currentPointIdx], points[nextPointIdx], points[i]) == 0 &&
                   isBetween(points[currentPointIdx], points[nextPointIdx], points[i])){
                    convexHullPoints.push_back(points[i]);
                }
            }
            if(nextPointIdx == minPointIdx){
                break;
            }else{
                convexHullPoints.push_back(points[nextPointIdx]);
                currentPointIdx = nextPointIdx;
            }   
        }
        
        return convexHullPoints;
    }
};