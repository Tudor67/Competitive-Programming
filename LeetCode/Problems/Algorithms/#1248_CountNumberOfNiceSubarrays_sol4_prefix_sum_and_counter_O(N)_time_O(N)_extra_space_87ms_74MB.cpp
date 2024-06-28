class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        const int N = nums.size();

        int niceSubarrays = 0;
        int parityPrefSum = 0;
        vector<int> freq(N + 1);
        freq[0] = 1;

        for(int i = 0; i < N; ++i){
            parityPrefSum += (nums[i] % 2);
            if(parityPrefSum - k >= 0){
                niceSubarrays += freq[parityPrefSum - k];
            }
            freq[parityPrefSum] += 1;
        }
        
        return niceSubarrays;
    }
};