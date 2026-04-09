class Solution {
public:
    int maxWalls(vector<int>& robots, vector<int>& distances, vector<int>& walls) {
        const int R = robots.size();
        const int W = walls.size();

        vector<int> sortedWalls = walls;
        sort(sortedWalls.begin(), sortedWalls.end());

        auto countWalls = [&sortedWalls](int l, int r) -> int {
            if(l > r){
                return 0;
            }
            return upper_bound(sortedWalls.begin(), sortedWalls.end(), r) -
                   lower_bound(sortedWalls.begin(), sortedWalls.end(), l);
        };

        vector<array<int, 3>> sortedRobotsDistances(R);
        for(int i = 0; i < R; ++i){
            sortedRobotsDistances[i] = {robots[i], distances[i], distances[i]};
        }

        sort(sortedRobotsDistances.begin(), sortedRobotsDistances.end());

        sortedRobotsDistances.push_back({INT_MAX, 0, 0});

        for(int i = R - 1; i >= 0; --i){
            sortedRobotsDistances[i][2] = min(sortedRobotsDistances[i][2],
                                              sortedRobotsDistances[i + 1][0] - sortedRobotsDistances[i][0] - 1);
            if(i >= 1){
                sortedRobotsDistances[i][1] = min(sortedRobotsDistances[i][1],
                                                  sortedRobotsDistances[i][0] - sortedRobotsDistances[i - 1][0] - 1);
            }
        }

        // dp[0][i]: max number of destroyed walls for sortedRobotsDistances[i .. R - 1]
        //           when sortedRobots[i] shoots to the left
        // dp[1][i]: max number of destroyed walls for sortedRobotsDistances[i .. R - 1]
        //           when sortedRobots[i] shoots to the right
        vector<vector<int>> dp(2, vector<int>(R + 1));

        for(int i = R - 1; i >= 0; --i){
            auto [currPos, currLeftDist, currRightDist] = sortedRobotsDistances[i];
            auto [nextPos, nextLeftDist, nextRightDist] = sortedRobotsDistances[i + 1];
            
            dp[0][i] = countWalls(currPos - currLeftDist, currPos) + max(dp[0][i + 1], dp[1][i + 1]);

            int optA = countWalls(currPos, currPos + currRightDist) + dp[1][i + 1];
            int optB = countWalls(currPos, min(currPos + currRightDist, nextPos - nextLeftDist - 1)) + dp[0][i + 1];
            dp[1][i] = max(optA, optB);
        }

        return max(dp[0][0], dp[1][0]);
    }
};