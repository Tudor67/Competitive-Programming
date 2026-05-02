class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        const int N = moves.length();
        const int L = count(moves.begin(), moves.end(), 'L');
        const int R = count(moves.begin(), moves.end(), 'R');
        const int EXTRA = N - (L + R);
        return abs(R - L) + EXTRA;
    }
};