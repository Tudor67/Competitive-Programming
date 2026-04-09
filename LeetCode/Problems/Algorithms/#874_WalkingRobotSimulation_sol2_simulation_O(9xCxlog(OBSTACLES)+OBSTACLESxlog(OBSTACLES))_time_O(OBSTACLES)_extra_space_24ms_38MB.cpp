class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        const vector<pair<int, int>> DIRECTIONS = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        set<pair<int, int>> obstaclesSet;
        for(const vector<int>& OBSTACLE: obstacles){
            obstaclesSet.insert({OBSTACLE[0], OBSTACLE[1]});
        }

        int x = 0;
        int y = 0;
        int dirIndex = 0;
        int maxSqDist = 0;

        for(int command: commands){
            if(command == -2){
                dirIndex = (dirIndex + 3) % 4;
            }else if(command == -1){
                dirIndex = (dirIndex + 1) % 4;
            }else{
                for(int i = 0; i < command; ++i){
                    int nextX = x + DIRECTIONS[dirIndex].first;
                    int nextY = y + DIRECTIONS[dirIndex].second;
                    if(obstaclesSet.contains({nextX, nextY})){
                        break;
                    }
                    x = nextX;
                    y = nextY;
                    int sqDist = x * x + y * y;
                    maxSqDist = max(maxSqDist, sqDist);
                }
            }
        }

        return maxSqDist;
    }
};