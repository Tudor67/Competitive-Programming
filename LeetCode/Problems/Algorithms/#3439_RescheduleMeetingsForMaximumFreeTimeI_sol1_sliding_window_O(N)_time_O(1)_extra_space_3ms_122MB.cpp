class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        const int N = startTime.size();

        int res = 0;
        int wSum = 0;
        for(int i = 0; i < N; ++i){
            wSum += (endTime[i] - startTime[i]);
            if(i >= k){
                wSum -= (endTime[i - k] - startTime[i - k]);
            }
            int l = (i >= k ? endTime[i - k] : 0);
            int r = (i + 1 < N ? startTime[i + 1] : eventTime);
            int freeTime = r - l - wSum;
            res = max(res, freeTime);
        }

        return res;
    }
};