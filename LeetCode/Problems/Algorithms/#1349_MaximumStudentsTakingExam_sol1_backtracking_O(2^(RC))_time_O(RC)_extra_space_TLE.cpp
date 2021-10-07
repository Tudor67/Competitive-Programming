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
    
    void back(int row, int col, int count, int& maxCount, vector<vector<char>>& seats){
        const int ROWS = seats.size();
        const int COLS = seats[0].size();
        maxCount = max(maxCount, count);
        if(row == ROWS){
            // stop
        }else if(col == COLS){
            back(row + 1, 0, count, maxCount, seats);
        }else if(isValid(row, col, ROWS, COLS, seats)){
            char initialSeat = seats[row][col];
            seats[row][col] = PERSON;
            back(row, col + 1, count + 1, maxCount, seats);
            seats[row][col] = initialSeat;
            back(row, col + 1, count, maxCount, seats);
        }else{
            back(row, col + 1, count, maxCount, seats);
        }
    }
    
public:
    int maxStudents(vector<vector<char>>& seats) {
        int maxCount = 0;
        back(0, 0, 0, maxCount, seats);
        return maxCount;
    }
};