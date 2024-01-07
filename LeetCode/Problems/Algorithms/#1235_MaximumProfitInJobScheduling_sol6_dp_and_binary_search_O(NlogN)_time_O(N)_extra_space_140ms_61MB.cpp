class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        const int N = startTime.size();

        vector<int> p(N);
        iota(p.begin(), p.end(), 0);
        sort(p.begin(), p.end(),
             [&](int lhs, int rhs){
                 return (startTime[lhs] < startTime[rhs]);
             });

        // maxProfit[i]: max profit for jobs with time in the range [startTime[p[i]] .. INF]
        vector<int> maxProfit(N + 1);
        for(int i = N - 1; i >= 0; --i){
            int l = i + 1;
            int r = N;
            while(l != r){
                int mid = (l + r) / 2;
                if(endTime[p[i]] <= startTime[p[mid]]){
                    r = mid;
                }else{
                    l = mid + 1;
                }
            }
            maxProfit[i] = max(maxProfit[i + 1], profit[p[i]] + maxProfit[r]);
        }

        return maxProfit[0];
    }
};