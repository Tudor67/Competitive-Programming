class Solution {
private:
    const long long INF = 1e16;

    long long computeMaxIncSubarraySumEndingAt(vector<int>& nums, int i){
        if(i - 1 < 0 || nums[i - 1] >= nums[i]){
            return -INF;
        }
        long long maxSum = nums[i - 1] + nums[i];
        long long currSum = nums[i];
        while(i - 1 >= 0 && nums[i - 1] < nums[i]){
            currSum += nums[i - 1];
            maxSum = max(maxSum, currSum);
            i -= 1;
        }
        return maxSum;
    }

    long long computeMaxIncSubarraySumStartingAt(vector<int>& nums, int i){
        const int N = nums.size();

        if(i + 1 >= N || nums[i] >= nums[i + 1]){
            return -INF;
        }

        long long maxSum = nums[i] + nums[i + 1];
        long long currSum = nums[i];
        while(i + 1 < N && nums[i] < nums[i + 1]){
            currSum += nums[i + 1];
            maxSum = max(maxSum, currSum);
            i += 1;
        }

        return maxSum;
    }

public:
    long long maxSumTrionic(vector<int>& nums) {
        const int N = nums.size();

        long long maxSum = -INF;

        int i = 0;
        while(i < N){
            int j = i;
            long long decSubarraySum = nums[j];
            while(j + 1 < N && nums[j] > nums[j + 1]){
                decSubarraySum += nums[j + 1];
                j += 1;
            }

            if(i < j){
                long long currSum = decSubarraySum - nums[i] - nums[j] +
                                    computeMaxIncSubarraySumEndingAt(nums, i) +
                                    computeMaxIncSubarraySumStartingAt(nums, j);
                maxSum = max(maxSum, currSum);
            }

            i = j + 1;
        }

        return maxSum;
    }
};