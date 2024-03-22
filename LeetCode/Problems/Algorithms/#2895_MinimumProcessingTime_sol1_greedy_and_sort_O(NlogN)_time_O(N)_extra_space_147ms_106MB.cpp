class Solution {
public:
    int minProcessingTime(vector<int>& processorTime, vector<int>& tasks) {
        const int N = processorTime.size();

        vector<int> sortedProcessorTimes = processorTime;
        vector<int> sortedTasks = tasks;

        sort(sortedProcessorTimes.begin(), sortedProcessorTimes.end());
        sort(sortedTasks.begin(), sortedTasks.end());

        int res = 0;
        for(int i = 0; i < N; ++i){
            int maxTime = sortedProcessorTimes[N - 1 - i] + sortedTasks[4 * i + 3];
            res = max(res, maxTime);
        }
        
        return res;
    }
};