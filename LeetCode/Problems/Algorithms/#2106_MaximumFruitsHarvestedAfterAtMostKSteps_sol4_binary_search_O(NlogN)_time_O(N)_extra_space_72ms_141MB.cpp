class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        const int N = fruits.size();
        const int INF = INT_MAX / 2;

        vector<int> suffSum(N + 1);
        for(int i = N - 1; i >= 0; --i){
            suffSum[i] = fruits[i][1] + suffSum[i + 1];
        }

        int res = 0;
        for(int i = 0; i < N; ++i){
            int lPos = fruits[i][0];
            if(lPos <= startPos && startPos - lPos <= k){
                int rPos = max(startPos, lPos + k - (startPos - lPos));
                int j = upper_bound(fruits.begin() + i, fruits.end(), vector<int>{rPos, INF}) - fruits.begin();
                res = max(res, suffSum[i] - suffSum[j]);
            }
        }

        for(int i = 0; i < N; ++i){
            int rPos = fruits[i][0];
            if(startPos <= rPos && rPos - startPos <= k){
                int lPos = min(startPos, rPos - k + (rPos - startPos));
                int j = lower_bound(fruits.begin(), fruits.begin() + i, vector<int>{lPos, -1}) - fruits.begin();
                res = max(res, suffSum[j] - suffSum[i + 1]);
            }
        }

        return res;
    }
};