struct Job{
    int startTime;
    int endTime;
    int profit;
    
    Job(int startTime, int endTime, int profit){
        this->startTime = startTime;
        this->endTime = endTime;
        this->profit = profit;
    }
    
    static bool incEndTimeComp(const Job& LHS, const Job& RHS){
        return (LHS.endTime < RHS.endTime);
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
        
        sort(sortedJobs.begin(), sortedJobs.end(), Job::incEndTimeComp);
        
        // dp[i]: max profit for sortedJobs[0 .. i]
        vector<int> dp(N);
        dp[0] = sortedJobs[0].profit;
        for(int i = 1; i < N; ++i){
            int l = 0;
            int r = i - 1;
            while(l != r){
                int mid = (l + r + 1) / 2;
                if(sortedJobs[mid].endTime <= sortedJobs[i].startTime){
                    l = mid;
                }else{
                    r = mid - 1;
                }
            }
            
            int j = r;
            if(sortedJobs[j].endTime <= sortedJobs[i].startTime){
                dp[i] = max(dp[i - 1], dp[j] + sortedJobs[i].profit);
            }else{
                dp[i] = max(dp[i - 1], sortedJobs[i].profit);
            }
        }
        
        return dp[N - 1];
    }
};