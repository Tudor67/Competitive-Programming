class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        const int N = startTime.size();

        vector<int> gaps;
        gaps.reserve(N + 2);

        int prevEnd = 0;
        for(int i = 0; i < N; ++i){
            gaps.push_back(startTime[i] - prevEnd);
            prevEnd = endTime[i];
        }
        gaps.push_back(eventTime - endTime[N - 1]);

        int res = 0;
        int wSum = 0;
        for(int i = 0; i < (int)gaps.size(); ++i){
            wSum += gaps[i];
            if(i >= k + 1){
                wSum -= gaps[i - (k + 1)];
            }
            res = max(res, wSum);
        }

        return res;
    }
};