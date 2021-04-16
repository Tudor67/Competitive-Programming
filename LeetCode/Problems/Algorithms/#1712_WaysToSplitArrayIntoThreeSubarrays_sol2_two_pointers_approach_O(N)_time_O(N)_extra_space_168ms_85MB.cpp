class Solution {
public:
    int waysToSplit(vector<int>& nums) {
        const int N = nums.size();
        const int MODULO = 1e9 + 7;
        
        vector<int> prefSum(N);
        partial_sum(nums.begin(), nums.end(), prefSum.begin());
        
        int answer = 0;
        for(int i = 0, j = 0, k = 0; i <= N - 3; ++i){
            for(j = max(i + 1, j); j <= N - 2 && 2 * prefSum[i] > prefSum[j]; ++j);
            for(k = max(j, k); k <= N - 2 && prefSum[i] + (prefSum[N - 1] - prefSum[i]) / 2 >= prefSum[k]; ++k);
            answer += (k - j);
            answer %= MODULO;
        }
        
        return answer;
    }
};