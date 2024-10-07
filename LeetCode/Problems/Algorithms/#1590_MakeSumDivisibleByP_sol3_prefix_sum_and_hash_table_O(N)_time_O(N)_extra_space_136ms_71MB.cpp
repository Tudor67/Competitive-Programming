class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        const int N = nums.size();

        int targetSum = 0;
        for(int num: nums){
            targetSum += num;
            targetSum %= p;
        }

        if(targetSum == 0){
            return 0;
        }

        int minLen = N;
        unordered_map<int, int> lastIndex;
        lastIndex[0] = -1;
        int prefSum = 0;
        for(int i = 0; i < N; ++i){
            prefSum += nums[i];
            prefSum %= p;
            int neededPrefSum = (prefSum - targetSum + p) % p;
            if(lastIndex.count(neededPrefSum)){
                minLen = min(minLen, i - lastIndex[neededPrefSum]);
            }
            lastIndex[prefSum] = i;
        }

        if(minLen == N){
            minLen = -1;
        }

        return minLen;
    }
};