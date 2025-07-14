class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        const int N = startTime.size();

        vector<int> prefMax(N);
        prefMax[0] = startTime[0];
        for(int i = 1; i < N; ++i){
            prefMax[i] = max(prefMax[i - 1], startTime[i] - endTime[i - 1]);
        }

        vector<int> suffMax(N);
        suffMax[N - 1] = eventTime - endTime[N - 1];
        for(int i = N - 2; i >= 0; --i){
            suffMax[i] = max(startTime[i + 1] - endTime[i], suffMax[i + 1]);
        }

        int res = 0;
        for(int i = 0; i < N; ++i){
            int l = (i > 0 ? endTime[i - 1] : 0);
            int r = (i + 1 < N ? startTime[i + 1] : eventTime);
            int totalTime = r - l;
            int busyTime = endTime[i] - startTime[i];
            if((i > 0 && prefMax[i - 1] >= busyTime) ||
               (i + 1 < N && suffMax[i + 1] >= busyTime)){
                res = max(res, totalTime);
            }else{
                res = max(res, totalTime - busyTime);
            }
        }

        return res;
    }
};