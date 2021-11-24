class Solution {
public:
    long long maxTaxiEarnings(int N, vector<vector<int>>& rides) {
        const int R = rides.size();
        
        unordered_map<int, vector<int>> buckets;
        for(int i = 0; i < R; ++i){
            int startPoint = rides[i][0];
            buckets[startPoint].push_back(i);
        }
        
        // maxProfit[endPoint]: max profit in the range [1 .. endPoint]
        vector<long long> maxProfit(N + 1);
        for(int startPoint = 1; startPoint <= N; ++startPoint){
            maxProfit[startPoint] = max(maxProfit[startPoint], maxProfit[startPoint - 1]);
            if(buckets.count(startPoint)){
                for(int i: buckets[startPoint]){
                    int endPoint = rides[i][1];
                    long long profit = rides[i][2] + (rides[i][1] - rides[i][0]);
                    maxProfit[endPoint] = max(maxProfit[endPoint], maxProfit[startPoint] + profit);
                }
            }
        }
        
        return maxProfit.back();
    }
};