class Solution {
public:
    int maxConsecutiveAnswers(string S, int K) {
        const int N = S.length();
        
        int maxConsecutive = 0;
        for(const char TARGET: {'T', 'F'}){
            int cost = 0;
            int i = 0;
            for(int j = 0; j < N; ++j){
                cost += (int)(S[j] != TARGET);
                while(cost > K){
                    cost -= (int)(S[i] != TARGET);
                    i += 1;
                }
                maxConsecutive = max(maxConsecutive, j - i + 1);
            }
        }
        
        return maxConsecutive;
    }
};