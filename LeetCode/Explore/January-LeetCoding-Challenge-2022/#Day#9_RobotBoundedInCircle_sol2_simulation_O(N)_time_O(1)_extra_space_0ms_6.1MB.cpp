class Solution {
public:
    bool isRobotBounded(string instructions) {
        static const vector<pair<int, int>> DIRECTIONS = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        
        int row = 0;
        int col = 0;
        int dirIdx = 0;
        for(int iteration = 1; iteration <= 4; ++iteration){
            for(char instruction: instructions){
                if(instruction == 'G'){
                    row += DIRECTIONS[dirIdx].first;
                    col += DIRECTIONS[dirIdx].second;
                }else if(instruction == 'L'){
                    dirIdx = (dirIdx - 1 + (int)DIRECTIONS.size()) % DIRECTIONS.size();
                }else if(instruction == 'R'){
                    dirIdx = (dirIdx + 1) % DIRECTIONS.size();
                }
            }
        }
        
        return (row == 0 && col == 0);
    }
};