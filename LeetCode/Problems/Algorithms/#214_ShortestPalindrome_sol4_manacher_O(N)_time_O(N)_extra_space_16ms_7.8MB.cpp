class Solution {
public:
    string shortestPalindrome(string s) {
        const int N = s.length();
        const int NN = 2 * N + 1;
        
        string ss(NN, '.');
        for(int i = 0; i < N; ++i){
            ss[2 * i + 1] = s[i];
        }
        
        vector<int> r(NN, 0);
        int rMaxIdx = 0;
        for(int i = 1; i < NN; ++i){
            if(i <= rMaxIdx + r[rMaxIdx]){
                r[i] = min(r[rMaxIdx - (i - rMaxIdx)], (rMaxIdx + r[rMaxIdx]) - i);
            }
            while(0 <= i - r[i] - 1 && i + r[i] + 1 < NN && ss[i - r[i] - 1] == ss[i + r[i] + 1]){
                r[i] += 1;
            }
            if(i + r[i] >= rMaxIdx + r[rMaxIdx]){
                rMaxIdx = i;
            }
        }
        
        int maxPalindromePrefixLength = 0;
        for(int i = 0; i < NN; ++i){
            if(r[i] == i){
                maxPalindromePrefixLength = i;
            }
        }
        
        return string(s.rbegin(), s.rbegin() + N - maxPalindromePrefixLength) + s;
    }
};