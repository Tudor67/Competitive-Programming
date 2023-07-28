class Solution {
private:
    double computeTotalTime(vector<int>& dist, int speed){
        double totalTime = 0;
        for(int d: dist){
            totalTime = ceil(totalTime);
            totalTime += d / (double)speed;
        }
        return totalTime;
    }

public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        const int N = dist.size();
        const int MAX_DIST = *max_element(dist.begin(), dist.end());

        int l = 1;
        int r = 100 * MAX_DIST + 1;
        while(l != r){
            int mid = (l + r) / 2;
            if(computeTotalTime(dist, mid) <= hour){
                r = mid;
            }else{
                l = mid + 1;
            }
        }

        if(computeTotalTime(dist, r) <= hour){
            return r;
        }

        return -1;
    }
};