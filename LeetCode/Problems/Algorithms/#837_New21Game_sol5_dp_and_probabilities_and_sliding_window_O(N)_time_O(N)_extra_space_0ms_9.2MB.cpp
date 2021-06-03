class Solution {
public:
    double new21Game(int N, int K, int W) {  
        if(K == 0){
            return 1;
        }
        
        double cumSum = 1;
        vector<double> p(N + 1, 0); 
        // p[i]: probability to gain i points in maximum min(i, K) steps
        p[0] = 1;
        for(int i = 1; i <= N; ++i){
            p[i] = cumSum / W;
            if(i >= W){
                cumSum -= p[i - W];
            }
            if(i <= K - 1){
                cumSum += p[i];
            }
        }
        
        return accumulate(p.begin() + K, p.begin() + N + 1, 0.0);
    }
};