class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        const int N = nums.size() / 3;
        
        vector<long long> leftMinSum(3 * N);
        priority_queue<int> maxHeap;
        long long sum = 0;
        for(int i = 0; i < 2 * N; ++i){
            maxHeap.push(nums[i]);
            sum += nums[i];
            if((int)maxHeap.size() == N + 1){
                sum -= maxHeap.top();
                maxHeap.pop();
            }
            if((int)maxHeap.size() == N){
                leftMinSum[i] = sum;
            }
        }
        
        vector<long long> rightMaxSum(3 * N);
        priority_queue<int, vector<int>, greater<int>> minHeap;
        sum = 0;
        for(int i = 3 * N - 1; i >= N; --i){
            minHeap.push(nums[i]);
            sum += nums[i];
            if((int)minHeap.size() == N + 1){
                sum -= minHeap.top();
                minHeap.pop();
            }
            if((int)minHeap.size() == N){
                rightMaxSum[i] = sum;
            }
        }
        
        long long minDiff = leftMinSum[N - 1] + rightMaxSum[N];
        for(int i = N - 1; i < 2 * N; ++i){
            long long diff = leftMinSum[i] - rightMaxSum[i + 1];
            minDiff = min(minDiff, diff);
        }
        
        return minDiff;
    }
};