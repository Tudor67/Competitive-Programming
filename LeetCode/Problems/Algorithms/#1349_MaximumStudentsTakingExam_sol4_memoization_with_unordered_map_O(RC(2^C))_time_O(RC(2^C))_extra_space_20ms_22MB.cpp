class Solution {
private:
    static const char BROKEN_SEAT = '#';
    static const char PERSON = 'p';
    const vector<pair<int, int>> DIRECTIONS = {{-1, -1}, {0, -1}, {0, 1}, {-1, 1}};
    
    bool isValid(int row, int col, const int& ROWS, const int& COLS, vector<vector<char>>& seats){
        for(const pair<int, int>& DIRECTION: DIRECTIONS){
            int nextRow = row + DIRECTION.first;
            int nextCol = col + DIRECTION.second;
            if(0 <= nextRow && nextRow < ROWS && 0 <= nextCol && nextCol < COLS){
                if(seats[nextRow][nextCol] == PERSON){
                    return false;
                }
            }
        }
        return (seats[row][col] != BROKEN_SEAT);
    }
    
    int solve(int row, int col, int prevColsMask, vector<vector<char>>& seats, unordered_map<int, int>& memo){
        const int ROWS = seats.size();
        const int COLS = seats[0].size();
        const int SIGNIFICANT_BITS = (1 << (COLS + 1)) - 1;
        if(row == ROWS){
            return 0;
        }
        if(col == COLS){
            return solve(row + 1, 0, prevColsMask, seats, memo);
        }
        int state = (row << 12) | (col << 9) | (prevColsMask);
        if(memo.count(state)){
            return memo[state];
        }
        int maxPersons = 0;
        if(isValid(row, col, ROWS, COLS, seats)){
            char initialSeat = seats[row][col];
            seats[row][col] = PERSON;
            maxPersons = max(maxPersons, 1 + solve(row, col + 1, ((prevColsMask << 1) | 1) & SIGNIFICANT_BITS, seats, memo));
            seats[row][col] = initialSeat;
            maxPersons = max(maxPersons, solve(row, col + 1, (prevColsMask << 1) & SIGNIFICANT_BITS, seats, memo));
        }else{
            maxPersons = solve(row, col + 1, (prevColsMask << 1) & SIGNIFICANT_BITS, seats, memo);
        }
        memo[state] = maxPersons;
        return maxPersons;
    }
    
public:
    int maxStudents(vector<vector<char>>& seats) {
        unordered_map<int, int> memo;
        return solve(0, 0, 0, seats, memo);
    }
};