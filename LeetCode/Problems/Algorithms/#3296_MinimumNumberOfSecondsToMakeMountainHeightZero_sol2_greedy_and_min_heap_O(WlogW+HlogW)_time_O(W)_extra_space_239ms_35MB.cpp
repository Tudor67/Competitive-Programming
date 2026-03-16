class Solution {
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        priority_queue<array<long long, 3>, vector<array<long long, 3>>, greater<>> minHeap;
        for(int workerTime: workerTimes){
            minHeap.push({workerTime, 1, workerTime});
        }

        long long minTime = 0;
        for(int h = 1; h <= mountainHeight; ++h){
            auto [workerTotalTime, x, workerTime] = minHeap.top();
            minHeap.pop();

            minTime = workerTotalTime;

            minHeap.push({workerTotalTime + workerTime * (x + 1), x + 1, workerTime});
        }

        return minTime;
    }
};