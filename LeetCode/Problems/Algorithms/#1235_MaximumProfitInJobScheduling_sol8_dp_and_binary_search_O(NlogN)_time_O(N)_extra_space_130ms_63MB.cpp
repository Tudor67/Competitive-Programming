struct Job{
    int startTime;
    int endTime;
    int profit;

    Job(int startTime, int endTime, int profit):
        startTime(startTime), endTime(endTime), profit(profit){
    }

    static bool incStartTimeComp(const Job& LHS, const Job& RHS){
        return (LHS.startTime < RHS.startTime);
    }
};

class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        const int N = startTime.size();

        vector<Job> sortedJobs;
        sortedJobs.reserve(N);
        for(int i = 0; i < N; ++i){
            sortedJobs.push_back(Job(startTime[i], endTime[i], profit[i]));
        }

        sort(sortedJobs.begin(), sortedJobs.end(), Job::incStartTimeComp);

        // maxProfit[i]: max profit for sortedJobs[i .. N - 1]
        //               jobs are sorted in increasing order of their start times
        vector<int> maxProfit(N + 1);
        for(int i = N - 1; i >= 0; --i){
            int r = lower_bound(sortedJobs.begin(), sortedJobs.end(), sortedJobs[i].endTime,
                                [](const Job& JOB, const int VAL){
                                    return (JOB.startTime < VAL);
                                })
                    - sortedJobs.begin();
            maxProfit[i] = max(maxProfit[i + 1], sortedJobs[i].profit + maxProfit[r]);
        }

        return maxProfit[0];
    }
};