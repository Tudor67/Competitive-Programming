class Solution {    
public:
    int minimumDifference(vector<int>& nums) {
        const int N = nums.size() / 2;
        const int TOTAL_SUM = accumulate(nums.begin(), nums.end(), 0);
        const int FULL_MASK = (1 << N) - 1;
        
        // Step 1: compute and save all possible sums that can be generated with nums[0 .. N - 1]
        //         sums[k] contains all sums that can be generated with k elements from nums[0 .. N - 1]
        vector<set<int>> sums(N + 1);
        for(int mask = 0; mask <= FULL_MASK; ++mask){
            int sum = 0;
            int bitsCount = 0;
            for(int bit = 0; bit < N; ++bit){
                if((mask >> bit) & 1){
                    sum += nums[bit];
                    bitsCount += 1;
                }
            }
            sums[bitsCount].insert(sum);
        }

        // Step 2: compute all possible sums that can be generated with nums[N ..  2 * N - 1]
        //         for a sum of k elements from nums[N .. 2 * N - 1]:
        //             find sum' of N - k elements from nums[0 .. N - 1]
        //             such that sum + sum' is closer to TOTAL_SUM / 2
        //         compute currentDiff = abs((sum + sum') - (TOTAL_SUM - (sum + sum')))
        //         update minDiff
        int minDiff = INT_MAX;
        for(int mask = 0; mask <= FULL_MASK && minDiff > 0; ++mask){
            int sum = 0;
            int bitsCount = 0;
            for(int bit = 0; bit < N; ++bit){
                if((mask >> bit) & 1){
                    sum += nums[N + bit];
                    bitsCount += 1;
                }
            }
            auto it = sums[N - bitsCount].lower_bound(TOTAL_SUM / 2 - sum);
            if(it != sums[N - bitsCount].end()){
                int rightSum = sum + *it;
                int leftSum = TOTAL_SUM - rightSum;
                minDiff = min(minDiff, abs(rightSum - leftSum));
            }
            if(it != sums[N - bitsCount].begin()){
                int rightSum = sum + *prev(it);
                int leftSum = TOTAL_SUM - rightSum;
                minDiff = min(minDiff, abs(rightSum - leftSum));
            }
        }
        
        return minDiff;
    }
};