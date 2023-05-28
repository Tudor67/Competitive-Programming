class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        const int N = stoneValue.size();
        const int K = 3;
        const int TOTAL_SUM = accumulate(stoneValue.begin(), stoneValue.end(), 0);
        const int INF = 1e9;
        
        // At (N - i)th iteration:
        //    maxScore[i % (K + 1)]: max score of a player when he starts the game at index i
        //                           both players play optimally
        vector<int> maxScore(K + 1, -INF);
        maxScore[N % (K + 1)] = 0;

        int suffSum = 0;
        for(int i = N - 1; i >= 0; --i){
            suffSum += stoneValue[i];
            maxScore[i % (K + 1)] = -INF;
            for(int j = i; j <= min(i + K - 1, N - 1); ++j){
                maxScore[i % (K + 1)] = max(maxScore[i % (K + 1)], suffSum - maxScore[(j + 1) % (K + 1)]);
            }
        }

        int alice = maxScore[0];
        int bob = TOTAL_SUM - alice;

        if(alice > bob){
            return "Alice";
        }else if(bob > alice){
            return "Bob";
        }
        return "Tie";
    }
};