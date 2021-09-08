#include <bits/stdc++.h>
using namespace std;

using Point = pair<int, int>;

class Solution {
private:
    long long computeOrientation(const Point& A, const Point& B, const Point& C){
        return 1LL * A.first * B.second + 1LL * B.first * C.second + 1LL * C.first * A.second
             - 1LL * A.second * B.first - 1LL * B.second * C.first - 1LL * C.second * A.first;
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
    vector<Point> convexHull(vector<Point>& points) {
        const int N = points.size();
        
        // Andrew's monotone chain algorithm
        vector<Point> lowerPoints;
        sort(points.begin(), points.end());
        addBoundaryPoints(points, lowerPoints);
        
        vector<Point> upperPoints;
        reverse(points.begin(), points.end());
        addBoundaryPoints(points, upperPoints);
        
        vector<Point> convexHullPoints = lowerPoints;
        if((int)convexHullPoints.size() < N){
            copy(upperPoints.begin() + 1, upperPoints.end() - 1, back_inserter(convexHullPoints));
        }
        
        return convexHullPoints;
    }
};

int main(){
    int N;
    cin >> N;

    vector<Point> points(N);
    for(int i = 0; i < N; ++i){
        cin >> points[i].first >> points[i].second;
    }

    vector<Point> convexHullPoints = Solution().convexHull(points);
    const int H = convexHullPoints.size();

    cout << H << "\n";
    for(const Point& P: convexHullPoints){
        cout << P.first << " " << P.second << "\n";
    }
    
    return 0;
}