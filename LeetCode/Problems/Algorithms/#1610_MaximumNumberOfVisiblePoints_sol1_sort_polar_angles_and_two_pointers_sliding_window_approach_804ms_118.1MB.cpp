class Solution {
private:
    const long double PI = 2 * asin((long double)1);
    
    long double angleDiff(const long double& polarAngleStart, const long double& polarAngleEnd){
        long double diff = (polarAngleEnd - polarAngleStart) * 180 / PI;
        if(diff < 0){
            diff += 360;
        }
        return diff;
    }
    
public:
    int visiblePoints(vector<vector<int>>& points, int angle, vector<int>& location) {
        int pointsAtCurrentLocation = 0;
        vector<long double> polarAngles;
        for(int i = 0; i < points.size(); ++i){
            if(points[i] == location){
                pointsAtCurrentLocation += 1;
            }else{
                polarAngles.push_back(atan2((long double)points[i][1] - location[1], (long double)points[i][0] - location[0]));
            }
        }
        
        sort(polarAngles.begin(), polarAngles.end());
        
        int maxVisiblePoints = 0;
        const int N = polarAngles.size();
        for(int i = 0, j = 0; j < 2 * N; ++j){
            while(j - i == N || angleDiff(polarAngles[i % N], polarAngles[j % N]) > angle){
                i += 1;
            }
            maxVisiblePoints = max(j - i + 1, maxVisiblePoints);
        }
        
        return maxVisiblePoints + pointsAtCurrentLocation;
    }
};