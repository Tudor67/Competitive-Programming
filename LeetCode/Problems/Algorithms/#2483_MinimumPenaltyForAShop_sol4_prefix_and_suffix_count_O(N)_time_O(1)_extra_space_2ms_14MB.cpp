class Solution {
public:
    int bestClosingTime(string customers) {
        const int N = customers.length();

        int prefN = 0;
        int suffY = count(customers.begin(), customers.end(), 'Y');
        pair<int, int> minCostTime = {N - suffY, N};

        for(int i = 0; i < N; ++i){
            minCostTime = min(minCostTime, {prefN + suffY, i});
            suffY -= (int)(customers[i] == 'Y');
            prefN += (int)(customers[i] == 'N');
        }

        return minCostTime.second;
    }
};