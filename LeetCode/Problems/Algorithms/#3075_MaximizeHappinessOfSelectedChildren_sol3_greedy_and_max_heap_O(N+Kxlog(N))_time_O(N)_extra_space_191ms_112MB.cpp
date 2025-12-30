class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        long long maxSum = 0;

        priority_queue<int> maxHeap(happiness.begin(), happiness.end());
        for(int turn = 1; turn <= k; ++turn){
            maxSum += max(0, maxHeap.top() - turn + 1);
            maxHeap.pop();
        }

        return maxSum;
    }
};