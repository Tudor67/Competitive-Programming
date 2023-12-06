class Solution {
public:
    long long minimumCost(string s) {
        const int N = s.length();

        long long minCost = 0;
        for(int i = 1; i < N; ++i){
            if(s[i - 1] != s[i]){
                minCost += min(i, N - i);
            }
        }

        return minCost;
    }
};