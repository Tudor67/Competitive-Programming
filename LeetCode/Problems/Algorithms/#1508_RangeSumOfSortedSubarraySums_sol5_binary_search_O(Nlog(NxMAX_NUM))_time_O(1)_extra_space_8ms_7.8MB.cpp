class Solution {
private:
    int countSumsLessOrEqual(vector<int>& nums, const int& MAX_SUM){
        // compute how many subarrays nums[i .. j] have a sum <= MAX_SUM
        const int N = nums.size();
        int count = 0;
        int sum = 0;
        int i = 0;
        for(int j = 0; j < N; ++j){
            sum += nums[j];
            while(sum > MAX_SUM){
                sum -= nums[i];
                i += 1;
            }
            count += (j - i + 1);
        }
        return count;
    }
    
    int kthSum(vector<int>& nums, int k){
        // compute sortedSubarraysSums[k - 1] (i.e., kth sum of subarrays nums[i .. j])
        const int N = nums.size();
        const int MAX_NUM = *max_element(nums.begin(), nums.end());
        int l = 0;
        int r = N * MAX_NUM;
        while(l != r){
            int mid = (l + r) / 2;
            if(countSumsLessOrEqual(nums, mid) < k){
                l = mid + 1;
            }else{
                r = mid;
            }
        }
        return r;
    }
    
    int computeTotalSum(vector<int>& nums, const int& K, const int& MODULO){
        // compute the total sum of sortedSubarraySums[0 .. K - 1]
        const int N = nums.size();
        
        long long totalSum = 0;
        long long maxSum = kthSum(nums, K);
        
        int count = 0;         // count = number of subarrays with sum <= maxSum
        int windowSum = 0;     // windowSum = nums[i] + nums[i + 1] + ... + nums[j], with windowSum <= maxSum
        int allWindowSums = 0; // allWindowSums = sum of nums[i .. j] + sum of nums[i + 1 .. j] + ... + sum of nums[j .. j]
                               //               = sum of all subarrays with a sum <= maxSum, ending with nums[j]
        int i = 0;
        for(int j = 0; j < N; ++j){
            windowSum += nums[j];
            allWindowSums += nums[j] * (j - i + 1);
            while(windowSum > maxSum){
                allWindowSums -= windowSum;
                windowSum -= nums[i];
                i += 1;
            }
            // sum of nums[i .. j] <= maxSum, sum of nums[i + 1 .. j] <= maxSum, ..., sum of nums[j .. j] <= maxSum
            // totalSum += sum of nums[i .. j] + sum of nums[i + 1 .. j] + ... + sum of nums[j .. j]
            totalSum += allWindowSums;
            totalSum %= MODULO;
            count += (j - i + 1);
        }
        
        // remove additional sums equal to maxSum (i.e., maxSums outside the [0 .. K - 1] range)
        totalSum -= ((count - K) * maxSum) % MODULO;
        totalSum += MODULO;
        totalSum %= MODULO;
        return totalSum;
    }
    
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        const int MODULO = 1e9 + 7;
        return (computeTotalSum(nums, right, MODULO) -
                computeTotalSum(nums, left - 1, MODULO) + MODULO) % MODULO;
    }
};