class Solution {
private:
    int computeDistanceToOrigin(const vector<int>& P){
        return (P[0] * P[0] + P[1] * P[1]);
    }
    
    int countPointsAtDistLessThanOrEqualTo(vector<vector<int>>& points, const int& DIST_THRESHOLD){
        int count = 0;
        for(const vector<int>& P: points){
            if(computeDistanceToOrigin(P) <= DIST_THRESHOLD){
                count += 1;
            }
        }
        return count;
    }
    
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int minDist = computeDistanceToOrigin(points[0]);
        int maxDist = computeDistanceToOrigin(points[0]);
        for(const vector<int>& P: points){
            int dist = computeDistanceToOrigin(P);
            minDist = min(minDist, dist);
            maxDist = max(maxDist, dist);
        }
        
        int l = minDist;
        int r = maxDist;
        while(l != r){
            int mid = (l + r) / 2;
            if(countPointsAtDistLessThanOrEqualTo(points, mid) < k){
                l = mid + 1;
            }else{
                r = mid;
            }
        }
        
        vector<vector<int>> closestPoints;
        int distThreshold = r;
        for(const vector<int>& P: points){
            if(computeDistanceToOrigin(P) <= distThreshold){
                closestPoints.push_back(P);
            }
            if((int)closestPoints.size() == k){
                break;
            }
        }
        
        return closestPoints;
    }
};