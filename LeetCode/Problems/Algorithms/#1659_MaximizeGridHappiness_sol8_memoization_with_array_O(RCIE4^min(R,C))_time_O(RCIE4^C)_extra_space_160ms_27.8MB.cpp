class Solution {
private:
    const int EMPTY = 0;
    const int INTROVERT = 1;
    const int EXTROVERT = 2;
    int ROWS;
    int COLS;
    int MAX_FULL_MASK;
    int memo[5][5][7][7][64][64];
    
    int countNeighbors(int col, int mask){
        const int LEFT_NEIGHBOR_MASK = 1;
        const int UP_NEIGHBOR_MASK = 1 << (COLS - 1);
        int neighbors = (col > 0 && (mask & LEFT_NEIGHBOR_MASK) > 0) + ((mask & UP_NEIGHBOR_MASK) > 0);
        return neighbors;
    }
    
    int computeHappinessContribution(int col, int personType, int introvertsMask, int extrovertsMask){
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
    
    int solve(int row, int col, int introvertsCount, int extrovertsCount, int introvertsMask, int extrovertsMask){
        if(row < ROWS && memo[row][col][introvertsCount][extrovertsCount][introvertsMask][extrovertsMask] != INT_MIN){
            return memo[row][col][introvertsCount][extrovertsCount][introvertsMask][extrovertsMask];
        }
        int maxGridHappiness = 0;
        if(row < ROWS && introvertsCount + extrovertsCount > 0){
            int nextRow = row;
            int nextCol = col + 1;
            if(nextCol == COLS){
                nextRow = row + 1;
                nextCol = 0;
            }
            if(introvertsCount >= 1){
                int happinessContribution = computeHappinessContribution(col, INTROVERT, introvertsMask, extrovertsMask);
                int nextIntrovertsMask = ((introvertsMask << 1) & MAX_FULL_MASK) + 1;
                int nextExtrovertsMask = (extrovertsMask << 1) & MAX_FULL_MASK;
                int gridHappiness = happinessContribution + solve(nextRow, nextCol, introvertsCount - 1, extrovertsCount, nextIntrovertsMask, nextExtrovertsMask);
                maxGridHappiness = max(gridHappiness, maxGridHappiness);
            }
            if(extrovertsCount >= 1){
                int happinessContribution = computeHappinessContribution(col, EXTROVERT, introvertsMask, extrovertsMask);
                int nextIntrovertsMask = (introvertsMask << 1) & MAX_FULL_MASK;
                int nextExtrovertsMask = ((extrovertsMask << 1) & MAX_FULL_MASK) + 1;
                int gridHappiness = happinessContribution + solve(nextRow, nextCol, introvertsCount, extrovertsCount - 1, nextIntrovertsMask, nextExtrovertsMask);
                maxGridHappiness = max(gridHappiness, maxGridHappiness);
            }
            int nextIntrovertsMask = (introvertsMask << 1) & MAX_FULL_MASK;
            int nextExtrovertsMask = (extrovertsMask << 1) & MAX_FULL_MASK;
            int gridHappiness = solve(nextRow, nextCol, introvertsCount, extrovertsCount, nextIntrovertsMask, nextExtrovertsMask);
            maxGridHappiness = max(gridHappiness, maxGridHappiness);
            memo[row][col][introvertsCount][extrovertsCount][introvertsMask][extrovertsMask] = maxGridHappiness;
        }
        return maxGridHappiness;
    }
    
public:
    int getMaxGridHappiness(int m, int n, int introvertsCount, int extrovertsCount) {
        this->ROWS = max(m, n);
        this->COLS = min(m, n);
        this->MAX_FULL_MASK = (1 << COLS) - 1;
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                for(int iCount = 0; iCount <= introvertsCount; ++iCount){
                    for(int eCount = 0; eCount <= extrovertsCount; ++eCount){
                        for(int iMask = 0; iMask <= MAX_FULL_MASK; ++iMask){
                            for(int eMask = 0; eMask <= MAX_FULL_MASK; ++eMask){
                                memo[row][col][iCount][eCount][iMask][eMask] = INT_MIN;
                            }
                        }
                    }
                }
            }
        }
        return solve(0, 0, introvertsCount, extrovertsCount, 0, 0);
    }
};