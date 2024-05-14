class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        const int N = happiness.size();

        priority_queue<int, vector<int>, greater<int>> minHeap;
        for(int h: happiness){
            minHeap.push(h);
            if((int)minHeap.size() > k){
                minHeap.pop();
            }
        }

        long long maxSum = 0;
        for(int i = k - 1; i >= 0; --i){
            maxSum += max(0, minHeap.top() - i);
            minHeap.pop();
        }

        return maxSum;
    }
};