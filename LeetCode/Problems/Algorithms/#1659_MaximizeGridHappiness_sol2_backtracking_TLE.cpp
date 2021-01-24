class Solution {
private:
    const int EMPTY = 0;
    const int INTROVERT = 1;
    const int EXTROVERT = 2;
    int ROWS;
    int COLS;
    int MAX_FULL_MASK;
    
    int countNeighbors(int col, int mask){
        const int LEFT_NEIGHBOR_MASK = 1;
        const int UP_NEIGHBOR_MASK = 1 << (COLS - 1);
        int neighbors = (col > 1 && (mask & LEFT_NEIGHBOR_MASK) > 0) + ((mask & UP_NEIGHBOR_MASK) > 0);
        return neighbors;
    }
    
    int happinessContribution(int col, int personType, int introvertsMask, int extrovertsMask){
        int contribution = 0;
        int introvertsNeighbors = countNeighbors(col, introvertsMask);
        int extrovertsNeighbors = countNeighbors(col, extrovertsMask);
        if(personType == INTROVERT){
            contribution = 120 - 30 * (introvertsNeighbors + extrovertsNeighbors) - 30 * introvertsNeighbors + 20 * extrovertsNeighbors;
        }else if(personType == EXTROVERT){
            contribution = 40 + 20 * (introvertsNeighbors + extrovertsNeighbors) - 30 * introvertsNeighbors + 20 * extrovertsNeighbors;
        }
        return contribution;
    }
    
    void back(int row, int col, int gridHappiness, int introvertsCount, int extrovertsCount, int introvertsMask, int extrovertsMask, int& answer){
        answer = max(gridHappiness, answer);
        if(row <= ROWS){
            int nextRow = row;
            int nextCol = col + 1;
            if(nextCol == COLS + 1){
                nextRow = row + 1;
                nextCol = 1;
            }
            if(introvertsCount >= 1){
                int nextGridHappiness = gridHappiness + happinessContribution(col, INTROVERT, introvertsMask, extrovertsMask);
                int nextIntrovertsMask = ((introvertsMask << 1) & MAX_FULL_MASK) + 1;
                int nextExtrovertsMask = (extrovertsMask << 1) & MAX_FULL_MASK;
                back(nextRow, nextCol, nextGridHappiness, introvertsCount - 1, extrovertsCount, nextIntrovertsMask, nextExtrovertsMask, answer);
            }
            if(extrovertsCount >= 1){
                int nextGridHappiness = gridHappiness + happinessContribution(col, EXTROVERT, introvertsMask, extrovertsMask);
                int nextIntrovertsMask = (introvertsMask << 1) & MAX_FULL_MASK;
                int nextExtrovertsMask = ((extrovertsMask << 1) & MAX_FULL_MASK) + 1;
                back(nextRow, nextCol, nextGridHappiness, introvertsCount, extrovertsCount - 1, nextIntrovertsMask, nextExtrovertsMask, answer);
            }
            int nextGridHappiness = gridHappiness;
            int nextIntrovertsMask = (introvertsMask << 1) & MAX_FULL_MASK;
            int nextExtrovertsMask = (extrovertsMask << 1) & MAX_FULL_MASK;
            back(nextRow, nextCol, nextGridHappiness, introvertsCount, extrovertsCount, nextIntrovertsMask, nextExtrovertsMask, answer);
        }
    }
    
public:
    int getMaxGridHappiness(int m, int n, int introvertsCount, int extrovertsCount) {
        this->ROWS = m;
        this->COLS = n;
        this->MAX_FULL_MASK = (1 << COLS) - 1;
        int answer = 0;
        back(1, 1, 0, introvertsCount, extrovertsCount, 0, 0, answer);
        return answer;
    }
};