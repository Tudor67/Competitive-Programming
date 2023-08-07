class Solution {
private:
    const int MODULO = 1e9 + 7;

    // solve(i, j, n, k, memo): number of possible playlists of length i
    //                          containing j unique songs (from a pool of n unique songs)
    int solve(int i, int j, int n, int k, vector<vector<int>>& memo){
        if(i == 0 && j == 0){
            return 1;
        }

        if(i == 0 || j == 0){
            return 0;
        }

        if(memo[i][j] != -1){
            return memo[i][j];
        }

        int res = 0;
        res = (res + (n - j + 1) * 1LL * solve(i - 1, j - 1, n, k, memo)) % MODULO;
        res = (res + max(0, j - k) * 1LL * solve(i - 1, j, n, k, memo)) % MODULO;

        memo[i][j] = res;
        return res;
    }

public:
    int numMusicPlaylists(int n, int goal, int k) {
        vector<vector<int>> memo(goal + 1, vector<int>(n + 1, -1));
        return solve(goal, n, n, k, memo);
    }
};