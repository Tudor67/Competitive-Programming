class Solution {
private:
    long long computeTotalTime(vector<int>& dist, int speed){
        const int N = dist.size();
        long long totalTime = 0;
        for(int i = 0; i < N - 1; ++i){
            totalTime += 100LL * ((dist[i] + speed - 1) / speed);
        }
        totalTime += (100LL * dist[N - 1] + speed - 1) / speed;
        return totalTime;
    }
    
public:
    int minSpeedOnTime(vector<int>& dist, double hourDouble) {
        long long hour = round(100 * hourDouble);
        int l = 1;
        int r = 1e8;
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