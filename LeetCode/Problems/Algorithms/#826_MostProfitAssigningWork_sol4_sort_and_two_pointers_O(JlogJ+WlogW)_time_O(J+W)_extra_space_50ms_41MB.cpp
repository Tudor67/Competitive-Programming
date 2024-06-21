class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        const int J = profit.size();
        const int W = worker.size();

        vector<pair<int, int>> sortedJobs(J);
        for(int i = 0; i < J; ++i){
            sortedJobs[i] = {difficulty[i], profit[i]};
        }
        sort(sortedJobs.begin(), sortedJobs.end());

        vector<int> sortedWorkers = worker;
        sort(sortedWorkers.begin(), sortedWorkers.end());

        int totalProfit = 0;
        int prefMaxProfit = 0;
        int jobIndex = 0;
        for(int wd: sortedWorkers){
            while(jobIndex < J && sortedJobs[jobIndex].first <= wd){
                prefMaxProfit = max(prefMaxProfit, sortedJobs[jobIndex].second);
                jobIndex += 1;
            }
            totalProfit += prefMaxProfit;
        }

        return totalProfit;
    }
};