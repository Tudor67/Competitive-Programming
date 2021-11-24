class Solution {
private:
    static bool incEndPointComp(const vector<int>& LHS, const vector<int>& RHS){
        return (LHS[1] < RHS[1]);
    }
    
public:
    long long maxTaxiEarnings(int N, vector<vector<int>>& rides) {
        const int R = rides.size();
        
        sort(rides.begin(), rides.end(), incEndPointComp);
        
        // maxProfit[i]: max profit in the range [0 .. i]
        vector<long long> maxProfit(R);
        maxProfit[0] = rides[0][2] + (rides[0][1] - rides[0][0]);
        for(int i = 1; i < R; ++i){
            int startPoint = rides[i][0];
            int endPoint = rides[i][1];
            long long profit = rides[i][2] + (rides[i][1] - rides[i][0]);
            
            // binary search
            int l = 0;
            int r = i;
            while(l != r){
                int mid = (l + r) / 2;
                if(rides[mid][1] <= startPoint){
                    l = mid + 1;
                }else{
                    r = mid;
                }
            }
            int j = r - 1;
            
            // update maxProfit
            if(0 <= j){
                maxProfit[i] = max(maxProfit[i - 1], maxProfit[j] + profit);
            }else{
                maxProfit[i] = max(maxProfit[i - 1], profit);
            }
        }
        
        return maxProfit.back();
    }
};