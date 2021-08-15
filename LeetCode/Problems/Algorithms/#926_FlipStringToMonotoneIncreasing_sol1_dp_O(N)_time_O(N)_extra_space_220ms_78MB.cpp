class Solution {
public:
    int minFlipsMonoIncr(string s) {
        const int N = s.length();
        // minFlips[i][0]: minimum number of flips to make s[0 .. i] monotone increasing and ending in '0';
        // minFlips[i][1]: minimum number of flips to make s[0 .. i] monotone increasing and ending in '1';
        vector<vector<int>> minFlips(N, vector<int>(2));
        minFlips[0][0] = (s[0] != '0');
        minFlips[0][1] = (s[0] != '1');
        for(int i = 1; i < N; ++i){
            int flipTo0 = (s[i] != '0');
            int flipTo1 = (s[i] != '1');
            minFlips[i][0] = minFlips[i - 1][0] + flipTo0;
            minFlips[i][1] = min(minFlips[i - 1][0], minFlips[i - 1][1]) + flipTo1;
        }
        return min(minFlips[N - 1][0], minFlips[N - 1][1]);
    }
};