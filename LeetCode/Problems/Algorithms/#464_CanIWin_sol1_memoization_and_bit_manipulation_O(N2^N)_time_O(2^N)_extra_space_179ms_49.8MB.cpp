class Solution {
private:
    bool canWin(int mask, int targetSum, const int& N, vector<int>& memo){
        if(memo[mask] != -1){
            return memo[mask];
        }
        int maxValidNum = 0;
        for(int bit = 0; bit < N; ++bit){
            if((mask >> bit) & 1){
                maxValidNum = bit + 1;
            }
        }
        if(targetSum <= maxValidNum){
            memo[mask] = true;
            return true;
        }
        for(int bit = 0; bit < N; ++bit){
            if((mask >> bit) & 1){
                if(!canWin(mask - (1 << bit), targetSum - (bit + 1), N, memo)){
                    memo[mask] = true;
                    return true;
                }
            }
        }
        memo[mask] = false;
        return false;
    }
    
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        const int N = maxChoosableInteger;
        const int FULL_MASK = (1 << N) - 1;
        
        if(N * (N + 1) / 2 < desiredTotal){
            return false;
        }
        
        vector<int> memo(FULL_MASK + 1, -1);
        return canWin(FULL_MASK, desiredTotal, N, memo);
    }
};