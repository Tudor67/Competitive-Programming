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

        vector<int> prefMaxProfit(J);
        prefMaxProfit[0] = sortedJobs[0].second;
        for(int i = 1; i < J; ++i){
            prefMaxProfit[i] = max(prefMaxProfit[i - 1], sortedJobs[i].second);
        }

        int totalProfit = 0;
        for(int wd: worker){
            int l = 0;
            int r = J - 1;
            while(l != r){
                int mid = (l + r + 1) / 2;
                if(sortedJobs[mid].first <= wd){
                    l = mid;
                }else{
                    r = mid - 1;
                }
            }

            if(sortedJobs[r].first <= wd){
                totalProfit += prefMaxProfit[r];
            }
        }

        return totalProfit;
    }
};