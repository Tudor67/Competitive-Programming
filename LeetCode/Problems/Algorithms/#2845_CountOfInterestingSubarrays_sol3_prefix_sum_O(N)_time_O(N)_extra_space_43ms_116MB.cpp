class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        const int N = nums.size();

        unordered_map<int, int> freq;
        freq[0] = 1;

        long long interestingSubarrays = 0;
        int prefCount = 0;
        for(int num: nums){
            prefCount += (int)(num % modulo == k);
            prefCount %= modulo;

            int targetPrefCount = (prefCount - k + modulo) % modulo;
            if(freq.count(targetPrefCount)){
                interestingSubarrays += freq[targetPrefCount];
            }

            freq[prefCount] += 1;
        }

        return interestingSubarrays;
    }
};