class Solution {
private:
    struct Worker{
        long long workerTotalTime;
        long long x;
        long long workerBaseTime;

        bool operator>(const Worker& other) const {
            return (workerTotalTime > other.workerTotalTime);
        }
    };

public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        priority_queue<Worker, vector<Worker>, greater<>> minHeap;
        for(int workerTime: workerTimes){
            minHeap.push({workerTime, 1, workerTime});
        }

        long long minTime = 0;
        for(int h = 1; h <= mountainHeight; ++h){
            auto [workerTotalTime, x, workerBaseTime] = minHeap.top();
            minHeap.pop();

            minTime = workerTotalTime;

            minHeap.push({workerTotalTime + workerBaseTime * (x + 1), x + 1, workerBaseTime});
        }

        return minTime;
    }
};