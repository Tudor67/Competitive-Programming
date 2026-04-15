class Solution {
private:
    const long long INF = LLONG_MAX / 10;

    long long computeMinCost(int r, int f, int fRemLimit, vector<int>& sortedRobots, vector<pair<int, int>>& sortedFactories, vector<vector<vector<long long>>>& memo){
        if(r < 0){
            return 0;
        }
        if(f < 0){
            return INF;
        }
        if(memo[r][f][fRemLimit] >= 0){
            return memo[r][f][fRemLimit];
        }
        long long minCost = INF;
        if(fRemLimit >= 1){
            long long takeCost = abs(sortedRobots[r] - sortedFactories[f].first) +
                                 computeMinCost(r - 1, f, fRemLimit - 1, sortedRobots, sortedFactories, memo);
            minCost = min(minCost, takeCost);
        }
        if(f >= 1){
            long long skipCost = computeMinCost(r, f - 1, sortedFactories[f - 1].second, sortedRobots, sortedFactories, memo);
            minCost = min(minCost, skipCost);
        }
        memo[r][f][fRemLimit] = minCost;
        return minCost;
    }

public:
    long long minimumTotalDistance(vector<int>& robots, vector<vector<int>>& factories) {
        const int R = robots.size();
        const int F = factories.size();
        const int C = (*max_element(factories.begin(), factories.end(),
                                    [](const vector<int>& LHS, const vector<int>& RHS){
                                        return (LHS[1] < RHS[1]);
                                    }))[1];

        vector<int> sortedRobots = robots;
        sort(sortedRobots.begin(), sortedRobots.end());

        vector<pair<int, int>> sortedFactories(F);
        for(int i = 0; i < F; ++i){
            sortedFactories[i] = {factories[i][0], factories[i][1]};
        }
        sort(sortedFactories.begin(), sortedFactories.end());

        vector<vector<vector<long long>>> memo(R, vector<vector<long long>>(F, vector<long long>(C + 1, -1)));
        return computeMinCost(R - 1, F - 1, sortedFactories.back().second, sortedRobots, sortedFactories, memo);
    }
};