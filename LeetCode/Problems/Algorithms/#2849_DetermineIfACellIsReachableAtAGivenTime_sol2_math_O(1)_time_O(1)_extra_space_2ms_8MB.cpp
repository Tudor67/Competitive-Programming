class Solution {
private:
    int abs(int x){
        return max(x, -x);
    }
    
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int dx = abs(sx - fx);
        int dy = abs(sy - fy);
        int minTime = max(dx, dy);

        if(minTime == 0){
            return (t != 1);
        }
        
        return (t >= minTime);
    }
};