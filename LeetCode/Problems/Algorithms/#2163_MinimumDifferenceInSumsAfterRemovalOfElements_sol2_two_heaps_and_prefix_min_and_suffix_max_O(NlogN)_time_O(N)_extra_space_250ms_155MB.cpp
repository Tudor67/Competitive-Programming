class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        const int N = nums.size() / 3;

        // Step 1: compute lMinSum[i]: min sum of N elements from nums[0 .. i]
        long long minSum = 0;
        vector<long long> lMinSum(3 * N);
        priority_queue<int> maxHeap;

        for(int i = 0; i < 3 * N; ++i){
            minSum += nums[i];
            maxHeap.push(nums[i]);
            if((int)maxHeap.size() > N){
                minSum -= maxHeap.top();
                maxHeap.pop();
            }
            if((int)maxHeap.size() == N){
                lMinSum[i] = minSum;
            }
        }

        // Step 2: compute rMaxSum[i]: max sum of N elements from nums[i + 1 .. ]
        long long maxSum = 0;
        vector<long long> rMaxSum(3 * N);
        priority_queue<int, vector<int>, greater<int>> minHeap;

        for(int i = 3 * N - 1; i >= 0; --i){
            maxSum += nums[i];
            minHeap.push(nums[i]);
            if((int)minHeap.size() > N){
                maxSum -= minHeap.top();
                minHeap.pop();
            }
            if((int)minHeap.size() == N){
                rMaxSum[i] = maxSum;
            }
        }

        // Step 3: compute the result = min(lMinSum[i] - rMaxSum[i + 1])
        long long res = lMinSum[N - 1] - rMaxSum[N];
        for(int i = N; i < 2 * N; ++i){
            res = min(res, lMinSum[i] - rMaxSum[i + 1]);
        }

        return res;
    }
};