class Solution {
public:
    string getSmallestString(int n, int k) {
        const char MAX_CHAR = 'z';
        string s(n, MAX_CHAR);
        int sum = 26 * n;
        for(int i = 0; i < n; ++i){
            int diff = min(25, sum - k);
            sum -= diff;
            s[i] -= diff;
        }
        return s;
    }
};