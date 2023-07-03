class Solution {
public:
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        const int N = locations.size();
        const int MODULO = 1e9 + 7;

        // dp[currentCity][currentFuel]: number of routes (% MODULO) from locations[start] to locations[currentCity]
        //                               when we have currentFuel units of fuel in the currentCity
        vector<vector<int>> dp(N, vector<int>(fuel + 1));
        set<pair<int, int>> statesSet;
        statesSet.insert({fuel, start});
        dp[start][fuel] = 1;

        while(!statesSet.empty()){
            int currentFuel = prev(statesSet.end())->first;
            int currentCity = prev(statesSet.end())->second;
            statesSet.erase(prev(statesSet.end()));

            for(int nextCity = 0; nextCity < N; ++nextCity){
                int dist = abs(locations[nextCity] - locations[currentCity]);
                if(currentCity != nextCity && dist <= currentFuel){
                    int nextFuel = currentFuel - dist;
                    dp[nextCity][nextFuel] = (dp[nextCity][nextFuel] + dp[currentCity][currentFuel]) % MODULO;
                    statesSet.insert({nextFuel, nextCity});
                }
            }
        }

        int res = 0;
        for(int f = 0; f <= fuel; ++f){
            res = (res + dp[finish][f]) % MODULO;
        }

        return res;
    }
};