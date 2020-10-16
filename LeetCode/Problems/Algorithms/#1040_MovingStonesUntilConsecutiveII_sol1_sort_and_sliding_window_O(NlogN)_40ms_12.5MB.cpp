class Solution {
public:
    vector<int> numMovesStonesII(vector<int>& stones) {
        const int N = stones.size();
        
        // Step 1: sort stones
        sort(stones.begin(), stones.end());
        
        // Step 2: find the window (of length N) which contains the most stones
        int maxOccupied = 0;
        for(int i = 0, j = 1; j < N; ++j){
            while(i < j && stones[j] - stones[i] + 1 > N){
                i += 1;
            }
            maxOccupied = max(j - i + 1, maxOccupied);
        }
        
        // Step 3: compute minMoves (take in consideration some edge cases)
        // Edge case: x, x + 1, x + 2, ... x + k, x + k + m, where m >= 3
        // Edge case: x, x + m, x + m + 1, x + m + 2, ... x + n - 1, x + n, where m >= 3
        int minMoves = N - maxOccupied;
        if(stones[N - 1] - stones[N - 2] >= 3 && stones[N - 2] - stones[0] + 1 == N - 1){
            minMoves = 2;
        }
        if(stones[1] - stones[0] >= 3 && stones[N - 1] - stones[1] + 1 == N - 1){
            minMoves = 2;
        }
        
        // Step 4: compute maxMoves
        int maxMoves = max(stones[N - 1] - stones[1], stones[N - 2] - stones[0]) - (N - 2);
        
        return {minMoves, maxMoves};
    }
};
/*
Testcases:
[1,5,6,9,10,15]
[3,4,5,6,10]
[1,6,7,8]
[1,3,4]
[1,2,4]
[1,3,8,9,10]
[1,3,4,5,6]
[1,2,3,4,8]
[1,7,10]
[1,7,10,14]
[7,4,9]
[6,5,4,3,10]
[100,101,104,102,103]
*/