class Solution {
public:
    long long minimumCost(string s) {
        const int N = s.length();
        const long long INF = 1e18;
        
        // pref[0][i]: min cost to make s[0 .. i] equal to zeros using only operations of type 1
        // pref[1][i]: min cost to make s[0 .. i] equal to ones using only operations of type 1
        vector<vector<long long>> pref(2, vector<long long>(N, INF));
        int firstBit = s[0] - '0';
        pref[firstBit][0] = 0;
        pref[firstBit ^ 1][0] = 1;
        
        for(int i = 1; i < N; ++i){
            int bit = s[i] - '0';
            pref[bit][i] = pref[bit][i - 1];
            pref[bit ^ 1][i] = pref[bit][i - 1] + (i + 1);
        }
        
        // suff[0][i]: min cost to make s[i .. N - 1] equal to zeros using only operations of type 2
        // suff[1][i]: min cost to make s[i .. N - 1] equal to ones using only operations of type 2
        vector<vector<long long>> suff(2, vector<long long>(N, INF));
        int lastBit = s[N - 1] - '0';
        suff[lastBit][N - 1] = 0;
        suff[lastBit ^ 1][N - 1] = 1;

        for(int i = N - 2; i >= 0; --i){
            int bit = s[i] - '0';
            suff[bit][i] = suff[bit][i + 1];
            suff[bit ^ 1][i] = (N - i) + suff[bit][i + 1];
        }
        
        // compute min cost to make s equal to zeros/ones using operations of type 1 and/or type 2
        long long minCost = min({pref[0][N - 1], pref[1][N - 1], suff[0][0], suff[1][0]});
        for(int i = 0; i + 1 < N; ++i){
            for(int bit = 0; bit <= 1; ++bit){
                long long cost = pref[bit][i] + suff[bit][i + 1];
                minCost = min(minCost, cost);
            }
        }

        return minCost;
    }
};