class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        const int N = timePoints.size();

        vector<int> t(N);
        for(int i = 0; i < N; ++i){
            string hh = timePoints[i].substr(0, 2);
            string mm = timePoints[i].substr(3);
            t[i] = stoi(hh) * 60 + stoi(mm);
        }

        sort(t.begin(), t.end());

        int minDiff = 24 * 60;
        for(int i = 0; i < N; ++i){
            int diff = abs(t[(i + 1) % N] - t[i]);
            minDiff = min(minDiff, min(diff, 24 * 60 - diff));
        }

        return minDiff;
    }
};