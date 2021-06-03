class Solution {
public:
    double new21Game(int N, int K, int W) {
        if(K == 0){
            return 1;
        }
        
        vector<vector<double>> p(N + 1, vector<double>(2, 0));
        // p[i][s]: probability to gain i points in s steps (with steps compression)
        
        for(int i = 1; i <= min(N, W); ++i){
            p[i][1] = 1.0 / W;
        }
        
        double answer = 0;
        for(int i = K; i <= N; ++i){
            answer += p[i][1];
        }
        
        for(int steps = 2; steps <= K; ++steps){
            double cumSum = 0;
            for(int j = max(steps - 1, steps - W); j <= min(steps - 1, K - 1); ++j){
                cumSum += p[j][(steps - 1) % 2];
            }
            
            for(int i = steps; i <= N; ++i){
                p[i][steps % 2] = cumSum * (1.0 / W);
                // sliding window
                if(i - W >= steps - 1){
                    cumSum -= p[i - W][(steps - 1) % 2];
                }
                if(i <= K - 1){
                    cumSum += p[i][(steps - 1) % 2];
                }
            }
            
            for(int i = K; i <= N; ++i){
                answer += p[i][steps % 2];
            }
        }
        
        return answer;
    }
};