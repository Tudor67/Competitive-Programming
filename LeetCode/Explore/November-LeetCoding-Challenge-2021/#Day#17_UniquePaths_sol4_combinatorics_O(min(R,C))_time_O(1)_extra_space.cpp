class Solution {
private:
    long long nCk(int n, int k){
        long long res = 1;
        for(int i = 1; i <= k; ++i){
            res *= (n - k + i);
            res /= i;
        }
        return res;
    }
    
public:
    int uniquePaths(int m, int n) {
        return nCk(m + n - 2, min(m, n) - 1);
    }
};

/*
  The robot moves from cell (1, 1) to cell (ROWS, COLS) in ROWS + COLS - 2 steps.
  It does ROWS - 1 down steps and COLS - 1 right steps.
  
  A path can be represented as a string s = "DRDDRR...R" ('D': down step, 'R': right step),
  such that the length of s is ROWS + COLS - 2, number of 'D' chars is ROWS - 1 and number of 'R' chars is COLS - 1.
  The order of 'D' and 'R' chars doesn't matter.
  
  Using the above observations, the initial problem is reduced to the problem of counting unique strings s
  which consist of ROWS - 1 chars equal to 'D' and COLS - 1 chars equal to 'R'.
  
  This is equivalent to counting all unique permutations of ROWS + COLS - 2 objects
  with ROWS - 1 identical objects of type 'D' and COLS - 1 identical objects of type 'R'.
  Formula: (ROWS + COLS - 2)! / ((ROWS - 1)!(COLS - 1)!).
  
  The above formula is the same as Comb(ROWS + COLS - 2, ROWS - 1) = Comb(ROWS + COLS - 2, COLS - 1).
  This is the number of ways to put 'D' chars (the remaining 'R' chars are fixed) in ROWS + COLS - 2 positions or
  the number of ways to put 'R' chars (the remaining 'D' chars are fixed) in ROWS + COLS - 2 positions.
*/