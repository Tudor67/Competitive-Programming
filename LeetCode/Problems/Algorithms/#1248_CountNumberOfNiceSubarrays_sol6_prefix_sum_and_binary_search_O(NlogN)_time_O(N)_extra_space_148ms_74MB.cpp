class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        const int N = nums.size();

        vector<int> parityPrefSum(N);
        parityPrefSum[0] = (nums[0] % 2);
        for(int i = 1; i < N; ++i){
            parityPrefSum[i] = parityPrefSum[i - 1] + (nums[i] % 2);
        }

        int niceSubarrays = 0;
        for(int i = 0; i < N; ++i){
            int prevParityPrefSum = (i == 0 ? 0 : parityPrefSum[i - 1]);
            niceSubarrays += upper_bound(parityPrefSum.begin() + i, parityPrefSum.end(), prevParityPrefSum + k) -
                             lower_bound(parityPrefSum.begin() + i, parityPrefSum.end(), prevParityPrefSum + k);
        }

        return niceSubarrays;
    }
};