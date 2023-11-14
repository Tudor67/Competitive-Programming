class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int dx = abs(sx - fx);
        int dy = abs(sy - fy);
        int minSteps = max(dx, dy);

        if(minSteps == 0){
            return (t != 1);
        }

        return (minSteps <= t);
    }
};