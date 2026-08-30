class Solution {
private:
    const int INF = INT_MAX;

    int computeMaxDiff(int i, vector<int>& stoneValues, vector<int>& memo){
        const int N = stoneValues.size();

        if(i >= N){
            return 0;
        }

        if(memo[i] != INF){
            return memo[i];
        }

        int maxDiff = -INF;
        int prefixSum = 0;
        for(int j = i; j <= min(i + 2, N - 1); ++j){
            prefixSum += stoneValues[j];
            maxDiff = max(maxDiff, prefixSum - computeMaxDiff(j + 1, stoneValues, memo));
        }

        memo[i] = maxDiff;
        return memo[i];
    }

public:
    string stoneGameIII(vector<int>& stoneValues) {
        const int N = stoneValues.size();

        vector<int> memo(N, INF);
        int maxDiff = computeMaxDiff(0, stoneValues, memo);

        if(maxDiff > 0){
            return "Alice";
        }else if(maxDiff < 0){
            return "Bob";
        }
        return "Tie";
    }
};