class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        const vector<pair<int, int>> DIRECTIONS = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

        set<pair<int, int>> obstaclesSet;
        for(const vector<int>& OBSTACLE: obstacles){
            obstaclesSet.insert({OBSTACLE[1], OBSTACLE[0]});
        }

        int maxSqrDist = 0;
        int dirIndex = 0;
        int y = 0;
        int x = 0;
        for(int command: commands){
            if(command >= 1){
                for(int i = 1; i <= command; ++i){
                    y += DIRECTIONS[dirIndex].first;
                    x += DIRECTIONS[dirIndex].second;
                    if(obstaclesSet.count({y, x})){
                        y -= DIRECTIONS[dirIndex].first;
                        x -= DIRECTIONS[dirIndex].second;
                        break;
                    }
                }
                maxSqrDist = max(maxSqrDist, x * x + y * y);
            }else if(command == -1){
                dirIndex = (dirIndex + 1) % (int)DIRECTIONS.size();
            }else{
                dirIndex = (dirIndex - 1 + (int)DIRECTIONS.size()) % (int)DIRECTIONS.size();
            }
        }

        return maxSqrDist;
    }
};