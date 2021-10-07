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
    
    int solve(int row, int col, vector<vector<char>>& seats){
        const int ROWS = seats.size();
        const int COLS = seats[0].size();
        int maxPersons = 0;
        if(row == ROWS){
            maxPersons = 0;
        }else if(col == COLS){
            maxPersons = solve(row + 1, 0, seats);
        }else if(isValid(row, col, ROWS, COLS, seats)){
            char initialSeat = seats[row][col];
            seats[row][col] = PERSON;
            maxPersons = max(maxPersons, 1 + solve(row, col + 1, seats));
            seats[row][col] = initialSeat;
            maxPersons = max(maxPersons, solve(row, col + 1, seats));
        }else{
            maxPersons = solve(row, col + 1, seats);
        }
        return maxPersons;
    }
    
public:
    int maxStudents(vector<vector<char>>& seats) {
        return solve(0, 0, seats);
    }
};