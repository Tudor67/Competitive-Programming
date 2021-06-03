class Solution {
public:
    double new21Game(int N, int K, int W) {
        vector<double> p(N + 1);
        // p[i]: probability to win when starting with i points
        
        for(int i = K; i <= N; ++i){
            p[i] = 1.0;
        }
        
        double cumSum = min(N - K + 1, W);
        for(int i = K - 1; i >= 0; --i){
            p[i] = cumSum / W;
            cumSum -= (i + W <= N ? p[i + W] : 0);
            cumSum += p[i];
        }
        
        return p[0];
    }
};