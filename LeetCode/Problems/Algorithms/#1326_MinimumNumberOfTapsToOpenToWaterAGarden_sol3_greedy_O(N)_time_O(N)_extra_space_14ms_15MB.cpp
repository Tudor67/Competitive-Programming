class Solution {
public:
    int minTaps(int N, vector<int>& ranges) {
        vector<int> maxStepAt(N + 1);
        for(int i = 0; i <= N; ++i){
            int l = max(0, i - ranges[i]);
            int r = min(N, i + ranges[i]);
            maxStepAt[l] = max(maxStepAt[l], r - l);
        }

        int taps = 0;
        int maxReachable = 0;
        int i = 0;
        while(i <= N && maxReachable < N && taps >= 0){
            if(maxReachable < i){
                taps = -1;
            }else{
                taps += 1;
                int newMaxReachable = maxReachable;
                while(i <= N && i <= maxReachable){
                    newMaxReachable = max(newMaxReachable, i + maxStepAt[i]);
                    i += 1;
                }
                maxReachable = newMaxReachable;
            }
        }

        return taps;
    }
};