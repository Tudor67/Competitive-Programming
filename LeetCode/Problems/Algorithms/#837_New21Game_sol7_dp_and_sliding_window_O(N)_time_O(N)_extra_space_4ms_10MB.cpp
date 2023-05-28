class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        if(n == 0 || k == 0){
            return 1;
        }

        // p[i]: probability of getting i points
        vector<double> p(n + 1);
        p[0] = 1;

        double res = 0;
        double wSum = 0;
        for(int i = 1; i <= n; ++i){
            if(i - 1 <= k - 1){
                wSum += p[i - 1];
            }

            int j = i - maxPts - 1;
            if(0 <= j && j <= k - 1){
                wSum -= p[j];
            }

            p[i] = wSum / maxPts;

            if(i >= k){
                res += p[i];
            }
        }

        return res;
    }
};