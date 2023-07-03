class Solution {
public:
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        const int N = locations.size();
        const int MODULO = 1e9 + 7;

        // dp[currentCity][currentFuel]: number of routes (% MODULO) from locations[start] to locations[currentCity]
        //                               when we have currentFuel units of fuel in the currentCity
        vector<vector<int>> dp(N, vector<int>(fuel + 1));
        dp[start][fuel] = 1;

        int res = 0;
        for(int currentFuel = fuel; currentFuel >= 0; --currentFuel){
            for(int currentCity = 0; currentCity < N; ++currentCity){
                for(int nextCity = 0; nextCity < N; ++nextCity){
                    int dist = abs(locations[nextCity] - locations[currentCity]);
                    if(currentCity != nextCity && dist <= currentFuel){
                        int nextFuel = currentFuel - dist;
                        dp[nextCity][nextFuel] = (dp[nextCity][nextFuel] + dp[currentCity][currentFuel]) % MODULO;
                    }
                }
            }
            res = (res + dp[finish][currentFuel]) % MODULO;
        }

        return res;
    }
};