class Solution {
private:
    bool isPossible(int level, int sum, int availableSticksMask, vector<int>& matchsticks,
                    const int& TARGET_SUM, vector<vector<int>>& memo){
        if(level == 0 || availableSticksMask == 0){
            return (level == 0 && availableSticksMask == 0);
        }
        
        if(memo[level][availableSticksMask] >= 0){
            return memo[level][availableSticksMask];
        }
        
        const int N = matchsticks.size();
        bool ok = false;
        for(int bit = 0; bit < N && !ok; ++bit){
            if((availableSticksMask >> bit) & 1){
                if(matchsticks[bit] <= sum){
                    int nextSum = sum - matchsticks[bit];
                    int nextLevel = level;
                    if(nextSum == 0){
                        nextSum = TARGET_SUM;
                        nextLevel = level - 1;
                    }
                    int nextAvailableSticksMask = availableSticksMask - (1 << bit);
                    ok = ok || isPossible(nextLevel, nextSum, nextAvailableSticksMask, matchsticks, TARGET_SUM, memo);
                }
            }
        }
        
        memo[level][availableSticksMask] = ok;
        return memo[level][availableSticksMask];
    }
    
public:
    bool makesquare(vector<int>& matchsticks) {
        const int N = matchsticks.size();
        const int FULL_MASK = (1 << N) - 1;
        const int MAX_STICK = *max_element(matchsticks.begin(), matchsticks.end());
        const int TOTAL_SUM = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        const int TARGET_SUM = TOTAL_SUM / 4;
        
        if(TOTAL_SUM % 4 != 0 || TARGET_SUM < MAX_STICK){
            return false;
        }
        
        // memo[`level`][`availableSticksMask`]: true (or 1), if is possible to partition sticks from `availableSticksMask`
        //                                                    into `level` subsets with sum equal to TARGET_SUM
        //                                       false (or 0), if is not possible
        //                                       -1, if this state has not been computed yet
        vector<vector<int>> memo(5, vector<int>(FULL_MASK + 1, -1));
        return isPossible(4, TARGET_SUM, FULL_MASK, matchsticks, TARGET_SUM, memo);
    }
};