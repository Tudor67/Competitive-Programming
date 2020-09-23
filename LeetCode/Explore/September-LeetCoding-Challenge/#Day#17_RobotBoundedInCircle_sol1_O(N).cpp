class Solution {
public:
    bool isRobotBounded(string instructions) {
        const vector<pair<int, int>> DIRECTIONS = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int directionIdx = 0;
        pair<int, int> currentPosition = {0, 0};
        for(int iteration = 1; iteration <= 4; ++iteration){
            for(char instruction: instructions){
                if(instruction == 'G'){
                    currentPosition.first += DIRECTIONS[directionIdx].first;
                    currentPosition.second += DIRECTIONS[directionIdx].second;
                }else if(instruction == 'L'){
                    directionIdx = (directionIdx - 1 + DIRECTIONS.size()) % DIRECTIONS.size();
                }else if(instruction == 'R'){
                    directionIdx = (directionIdx + 1 + DIRECTIONS.size()) % DIRECTIONS.size();
                }
            }
        }
        return currentPosition == pair<int, int>{0, 0};
    }
};