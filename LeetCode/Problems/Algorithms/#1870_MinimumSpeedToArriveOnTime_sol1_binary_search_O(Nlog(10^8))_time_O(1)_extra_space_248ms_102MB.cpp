class Solution {
private:
    double computeTotalTime(vector<int>& dist, double speed){
        const int N = dist.size();
        double totalTime = 0;
        for(int i = 0; i < N - 1; ++i){
            totalTime += ceil(dist[i] / speed);
        }
        totalTime += (dist[N - 1] / speed);
        return totalTime;
    }
    
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
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