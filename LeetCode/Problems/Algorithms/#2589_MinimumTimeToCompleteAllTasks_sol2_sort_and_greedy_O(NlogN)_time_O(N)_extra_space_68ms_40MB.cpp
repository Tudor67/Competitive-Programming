class Solution {
public:
    int findMinimumTime(vector<vector<int>>& tasks) {
        const int N = tasks.size();
        const int INF = 1e9 + 33;

        using Task3 = array<int, 3>;
        vector<Task3> sortedTasks(N + 1);
        for(int i = 0; i < N; ++i){
            sortedTasks[i][0] = tasks[i][0];
            sortedTasks[i][1] = tasks[i][1];
            sortedTasks[i][2] = tasks[i][2];
        }
        sortedTasks[N] = {INF, INF, 1};

        // the tasks will be processed in increasing order of their original startTimes
        sort(sortedTasks.begin(), sortedTasks.end());

        // the minHeap will maintain the overlapping tasks
        // for the current task we push into the minHeap: {shifted latest start time of the task, end time of the task}
        using Task2 = array<int, 2>;
        priority_queue<Task2, vector<Task2>, greater<Task2>> minHeap;

        int res = 0;
        for(int i = 0; i <= N; ++i){
            int s = sortedTasks[i][0];
            int e = sortedTasks[i][1];
            int d = sortedTasks[i][2];
            while(!minHeap.empty() && minHeap.top()[0] + res <= s - 1){
                if(minHeap.top()[0] + res > minHeap.top()[1]){
                    // `minHeap.top() task` is completed
                    minHeap.pop();
                }else{
                    // run `minHeap.top() task` without exceeding time (s - 1)
                    // because times s, s + 1, s + 2, ... maxTime can be shared later with sortedTasks[i + 1 .. N]
                    res += min(minHeap.top()[1], s - 1) - (minHeap.top()[0] + res) + 1;
                }
            }
            minHeap.push({e - d + 1 - res, e});
        }

        return res;
    }
};