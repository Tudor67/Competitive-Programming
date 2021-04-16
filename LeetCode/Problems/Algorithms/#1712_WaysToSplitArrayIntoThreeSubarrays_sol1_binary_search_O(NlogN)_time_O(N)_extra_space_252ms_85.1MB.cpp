class Solution {
public:
    int waysToSplit(vector<int>& nums) {
        const int N = nums.size();
        const int MODULO = 1e9 + 7;
        
        vector<int> prefSum(N);
        partial_sum(nums.begin(), nums.end(), prefSum.begin());
        
        int answer = 0;
        for(int i = 0; i <= N - 3; ++i){
            int s = prefSum[N - 1] - prefSum[i];
            int j = lower_bound(prefSum.begin() + i + 1, prefSum.begin() + N - 1, 2 * prefSum[i]) - prefSum.begin();
            int k = upper_bound(prefSum.begin() + j, prefSum.begin() + N - 1, prefSum[i] + s / 2) - prefSum.begin();
            answer += (k - j);
            answer %= MODULO;
        }
        
        return answer;
    }
};