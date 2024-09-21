class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        const int N = timePoints.size();
        const int MAX_MINUTES = 1440; // 1440 = 24 * 60

        vector<int> freq(MAX_MINUTES);
        int maxTime = -1;
        for(int i = 0; i < N; ++i){
            string hh = timePoints[i].substr(0, 2);
            string mm = timePoints[i].substr(3);
            int t = stoi(hh) * 60 + stoi(mm);
            freq[t] += 1;
            maxTime = max(maxTime, t);
        }

        int minDiff = MAX_MINUTES;
        int prevTime = maxTime;
        for(int t = 0; t < MAX_MINUTES; ++t){
            while(freq[t] >= 1){
                int diff = abs(t - prevTime);
                minDiff = min(minDiff, min(diff, MAX_MINUTES - diff));
                prevTime = t;
                freq[t] -= 1;
            }
        }

        return minDiff;
    }
};