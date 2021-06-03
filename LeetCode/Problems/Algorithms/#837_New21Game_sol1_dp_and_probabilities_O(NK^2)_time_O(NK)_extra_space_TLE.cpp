class Solution {
public:
    double new21Game(int N, int K, int W) {
        if(K == 0){
            return 1;
        }
        
        vector<vector<double>> p(N + 1, vector<double>(K + 1, 0));
        // p[i][s]: probability to gain i points in s steps
        
        for(int i = 1; i <= min(N, W); ++i){
            p[i][1] = 1.0 / W;
        }
        
        for(int steps = 2; steps <= K; ++steps){
            for(int i = steps; i <= N; ++i){
                for(int j = max(steps - 1, i - W); j <= min(i - 1, K - 1); ++j){
                    p[i][steps] += p[j][steps - 1] * (1.0 / W);
                }
            }
        }
        
        double answer = 0;
        for(int i = K; i <= N; ++i){
            for(int steps = 1; steps <= K; ++steps){
                answer += p[i][steps];
            }
        }
        
        return answer;
    }
};