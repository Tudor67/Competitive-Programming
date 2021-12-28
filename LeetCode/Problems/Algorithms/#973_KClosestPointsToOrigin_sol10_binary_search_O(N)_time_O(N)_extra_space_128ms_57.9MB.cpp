class Solution {
private:
    int computeDistanceToOrigin(const vector<int>& P){
        return (P[0] * P[0] + P[1] * P[1]);
    }
    
    int computeDistanceToOrigin(const pair<int, int>& P){
        return (P.first * P.first + P.second * P.second);
    }
    
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {        
        int currentK = k;
        vector<pair<int, int>> leftPoints;
        vector<pair<int, int>> rightPoints;
        vector<pair<int, int>> currentPoints;
        for(const vector<int>& P: points){
            currentPoints.emplace_back(P[0], P[1]);
        }
        
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
            
            leftPoints.clear();
            rightPoints.clear();
            for(const pair<int, int>& P: currentPoints){
                if(computeDistanceToOrigin(P) < mid){
                    leftPoints.push_back(P);
                }else{
                    rightPoints.push_back(P);
                }
            }
            
            if((int)leftPoints.size() < currentK){
                currentK -= (int)leftPoints.size();
                currentPoints = rightPoints;
                l = mid + 1;
            }else{
                currentPoints = leftPoints;
                r = mid;
            }
        }
        
        int distThreshold = r;
        vector<vector<int>> closestPoints;
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