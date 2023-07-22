class Solution {
public:
    int minOperations(vector<int>& nums) {
        const int N = nums.size();
        const int ONES = count(nums.begin(), nums.end(), 1);

        // Step 1: special case when gcd(nums[0 .. N - 1]) != 1 => return -1
        int numsGCD = nums[0];
        for(int num: nums){
            numsGCD = gcd(numsGCD, num);
        }

        if(numsGCD != 1){
            return -1;
        }

        // Step 2: if nums contains at least one num = 1 => return (N - ONES);
        if(ONES >= 1){
            return N - ONES;
        }

        // Step 3: find the shortest subarray nums[i .. j] with gcd = 1
        //         apply (minLen - 1) operations on that subarray to make one num = 1
        //         apply (N - 1) operations on the remaing nums
        //         return (N - 1) + (minLen - 1)
        int minLen = INT_MAX;
        for(int i = 0; i < N; ++i){
            int subarrayGCD = nums[i];
            for(int j = i; j < N; ++j){
                subarrayGCD = gcd(subarrayGCD, nums[j]);
                if(subarrayGCD == 1){
                    minLen = min(minLen, j - i + 1);
                    break;
                }
            }
        }

        return (N - 1) + (minLen - 1);
    }
};