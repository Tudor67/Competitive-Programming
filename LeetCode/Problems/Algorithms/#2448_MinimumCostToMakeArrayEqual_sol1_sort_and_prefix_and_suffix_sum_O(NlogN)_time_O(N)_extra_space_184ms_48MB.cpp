class Solution {
public:
    long long minCost(vector<int>& inNums, vector<int>& inCost) {
        const int N = inNums.size();
        
        vector<pair<int, int>> v(N);
        for(int i = 0; i < N; ++i){
            v[i] = {inNums[i], inCost[i]};
        }
        
        sort(v.begin(), v.end());
        
        vector<long long> nums(N);
        vector<long long> cost(N);
        for(int i = 0; i < N; ++i){
            nums[i] = v[i].first;
            cost[i] = v[i].second;
        }
        
        vector<long long> prefCost(N);
        prefCost[0] = cost[0];
        for(int i = 1; i < N; ++i){
            prefCost[i] = prefCost[i - 1] + cost[i];
        }
        
        vector<long long> suffCost(N);
        suffCost[N - 1] = cost[N - 1];
        for(int i = N - 2; i >= 0; --i){
            suffCost[i] = cost[i] + suffCost[i + 1];
        }
        
        vector<long long> lRes(N);
        for(int i = 1; i < N; ++i){
            lRes[i] = lRes[i - 1] + (nums[i] - nums[i - 1]) * prefCost[i - 1];
        }
        
        vector<long long> rRes(N);
        for(int i = N - 2; i >= 0; --i){
            rRes[i] = (nums[i + 1] - nums[i]) * suffCost[i + 1] + rRes[i + 1];
        }
        
        long long res = lRes[0] + rRes[0];
        for(int i = 0; i < N; ++i){
            res = min(res, lRes[i] + rRes[i]);
        }
        
        return res;
    }
};