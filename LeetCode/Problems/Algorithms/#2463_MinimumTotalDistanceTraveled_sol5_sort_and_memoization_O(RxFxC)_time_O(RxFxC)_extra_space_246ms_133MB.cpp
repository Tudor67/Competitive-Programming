class Solution {
private:
    const long long INF = 1e15;

    long long computeMinDistance(int r, int f, int c, vector<int>& robots, vector<vector<int>>& factories,
                                 vector<vector<vector<long long>>>& memo){
        if(r >= (int)robots.size()){
            return 0;
        }

        if(f >= (int)factories.size()){
            return INF;
        }

        c = min(c, factories[f][1]);
        if(memo[r][f][c] != INF){
            return memo[r][f][c];
        }

        long long res = computeMinDistance(r, f + 1, INT_MAX, robots, factories, memo);
        if(c >= 1){
            res = min(res, abs(robots[r] - factories[f][0]) +
                           computeMinDistance(r + 1, f, c - 1, robots, factories, memo));
        }

        memo[r][f][c] = res;
        return res;
    }

public:
    long long minimumTotalDistance(vector<int>& robots, vector<vector<int>>& factories) {
        const int R = robots.size();
        const int F = factories.size();

        sort(robots.begin(), robots.end());
        sort(factories.begin(), factories.end());

        int maxFactoryCapacity = 0;
        for(int i = 0; i < F; ++i){
            maxFactoryCapacity = max(maxFactoryCapacity, factories[i][1]);
        }
        
        vector<vector<vector<long long>>> memo(R, vector<vector<long long>>(F,
                                               vector<long long>(maxFactoryCapacity + 1, INF)));
        return computeMinDistance(0, 0, factories[0][1], robots, factories, memo);
    }
};