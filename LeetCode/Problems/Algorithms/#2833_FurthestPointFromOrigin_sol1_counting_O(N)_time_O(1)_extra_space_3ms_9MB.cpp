class Solution {
public:
    int furthestDistanceFromOrigin(string s) {
        const int L = count(s.begin(), s.end(), 'L');
        const int R = count(s.begin(), s.end(), 'R');
        const int X = count(s.begin(), s.end(), '_');
        return max(L, R) - min(L, R) + X;
    }
};