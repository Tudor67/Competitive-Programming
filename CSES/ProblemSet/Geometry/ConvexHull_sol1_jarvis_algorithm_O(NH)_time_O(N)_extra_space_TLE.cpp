#include <bits/stdc++.h>
using namespace std;

using Point = pair<int, int>;

class Solution {
private:
    long long computeOrientation(const Point& A, const Point& B, const Point& C){
        return 1LL * A.first * B.second + 1LL * B.first * C.second + 1LL * C.first * A.second
             - 1LL * A.second * B.first - 1LL * B.second * C.first - 1LL * C.second * A.first;
    }
    
    bool isBetween(const Point& A, const Point& B, const Point& C){
        return min(A.first, B.first) <= C.first && C.first <= max(A.first, B.first) &&
               min(A.second, B.second) <= C.second && C.second <= max(A.second, B.second);
    }
    
public:
    vector<Point> convexHull(vector<Point>& points) {
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