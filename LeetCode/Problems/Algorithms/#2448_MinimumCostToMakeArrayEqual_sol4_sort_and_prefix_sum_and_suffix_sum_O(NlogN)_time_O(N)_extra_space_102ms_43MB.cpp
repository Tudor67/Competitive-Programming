class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        const int N = nums.size();

        vector<pair<int, int>> sortedNumsCost(N);
        for(int i = 0; i < N; ++i){
            sortedNumsCost[i] = {nums[i], cost[i]};
        }

        sort(sortedNumsCost.begin(), sortedNumsCost.end());
        
        vector<long long> leftRes(N);
        long long prefCost = 0;
        for(int i = 1; i < N; ++i){
            prefCost += sortedNumsCost[i - 1].second;
            long long numsDiff = sortedNumsCost[i].first - sortedNumsCost[i - 1].first;
            leftRes[i] = leftRes[i - 1] + numsDiff * prefCost;
        }

        vector<long long> rightRes(N);
        long long suffCost = 0;
        for(int i = N - 2; i >= 0; --i){
            suffCost += sortedNumsCost[i + 1].second;
            long long numsDiff = sortedNumsCost[i + 1].first - sortedNumsCost[i].first;
            rightRes[i] = numsDiff * suffCost + rightRes[i + 1];
        }

        long long res = leftRes[0] + rightRes[0];
        for(int i = 1; i < N; ++i){
            res = min(res, leftRes[i] + rightRes[i]);
        }

        return res;
    }
};