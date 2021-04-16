class Solution {
public:
    int superEggDrop(int k, int n) {
        if(k == 1){
            return n;
        }
        
        const int MAX_MOVES = 145;
        // f[k][m]: max number of floors we can determine
        //          with k eggs and m moves
        vector<vector<int>> f(k + 1, vector<int>(MAX_MOVES + 1));
        
        for(int i = 1; i <= k; ++i){
            f[i][1] = 1;
        }
        
        for(int j = 1; j <= MAX_MOVES; ++j){
            f[1][j] = j;
        }
        
        for(int i = 2; i <= k; ++i){
            for(int j = 1; j <= MAX_MOVES; ++j){
                f[i][j] = 1 + f[i - 1][j - 1] + f[i][j - 1];
                if(f[i][j] >= n){
                    break;
                }
            }
        }
        
        int answer = MAX_MOVES;
        for(int j = 1; j <= MAX_MOVES; ++j){
            if(f[k][j] >= n){
                answer = j;
                break;
            }
        }
        
        return answer;
    }
};