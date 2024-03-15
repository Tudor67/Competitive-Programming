class Solution {
public:
    long long maximumSumOfHeights(vector<int>& maxHeights) {
        const int N = maxHeights.size();

        long long res = 0;
        for(int i = 0; i < N; ++i){
            long long sum = maxHeights[i];
            int currHeight = maxHeights[i];
            for(int j = i - 1; j >= 0; --j){
                currHeight = min(currHeight, maxHeights[j]);
                sum += currHeight;
            }

            currHeight = maxHeights[i];
            for(int j = i + 1; j < N; ++j){
                currHeight = min(currHeight, maxHeights[j]);
                sum += currHeight;
            }

            res = max(res, sum);
        }

        return res;
    }
};