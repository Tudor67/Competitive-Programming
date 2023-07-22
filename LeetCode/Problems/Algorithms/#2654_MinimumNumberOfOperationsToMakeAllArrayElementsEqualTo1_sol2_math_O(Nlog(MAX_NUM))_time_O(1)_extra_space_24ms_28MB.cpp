class Solution {
private:
    const int INF = 1e9;

    int computeMinLenForGCD1(vector<int>& nums, int startPos, int direction){
        const int N = nums.size();
        
        if(startPos < 0 || N <= startPos){
            return INF;
        }

        int i = startPos;
        int subarrayGCD = nums[i];
        while(0 <= i && i < N && subarrayGCD != 1){
            subarrayGCD = gcd(subarrayGCD, nums[i]);
            i += direction;
        }
        if(subarrayGCD == 1){
            return abs(startPos - i);
        }
        return INF;
    }

public:
    int minOperations(vector<int>& nums) {
        const int N = nums.size();
        const int ONES = count(nums.begin(), nums.end(), 1);

        // Step 1: special case when gcd(nums[0 .. N - 1]) != 1 => return -1;
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

        // Step 3: find the shortest subarray of nums with gcd = 1
        //         apply (minLen - 1) operations on that subarray to make one num = 1
        //         apply (N - 1) operations on the remaining elements of nums
        //         return (N - 1) + (minLen - 1);
        int minLen = INF;
        int i = 0;
        while(i < N){
            int l1 = computeMinLenForGCD1(nums, i, 1);
            int l2 = computeMinLenForGCD1(nums, i + l1 - 1, -1);
            minLen = min(minLen, l2);
            i += l1 - 1;
        }

        return (N - 1) + (minLen - 1);
    }
};