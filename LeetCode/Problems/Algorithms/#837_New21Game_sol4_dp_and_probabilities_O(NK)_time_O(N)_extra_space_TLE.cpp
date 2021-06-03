class Solution {
public:
    double new21Game(int N, int K, int W) {
        if(K == 0){
            return 1;
        }
        
        vector<vector<double>> p(2, vector<double>(N + 1, 0));
        // p[s][i]: probability to gain i points after s steps (with steps compression)
        
        for(int i = 1; i <= min(N, W); ++i){
            p[1][i] = 1.0 / W;
        }
        
        double answer = 0;
        for(int i = K; i <= N; ++i){
            answer += p[1][i];
        }
        
        for(int steps = 2; steps <= K; ++steps){
            double cumSum = 0;
            for(int j = max(steps - 1, steps - W); j <= min(steps - 1, K - 1); ++j){
                cumSum += p[(steps - 1) % 2][j];
            }
            
            for(int i = steps; i <= N; ++i){
                p[steps % 2][i] = cumSum * (1.0 / W);
                // sliding window
                if(i - W >= steps - 1){
                    cumSum -= p[(steps - 1) % 2][i - W];
                }
                if(i <= K - 1){
                    cumSum += p[(steps - 1) % 2][i];
                }
            }
            
            for(int i = K; i <= N; ++i){
                answer += p[steps % 2][i];
            }
        }
        
        return answer;
    }
};