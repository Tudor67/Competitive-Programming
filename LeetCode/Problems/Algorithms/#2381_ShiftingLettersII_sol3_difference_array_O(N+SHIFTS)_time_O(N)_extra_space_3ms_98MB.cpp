class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        const int N = s.length();
        const int A = 26;

        vector<int> delta(N + 1);
        for(const vector<int>& SHIFT: shifts){
            int l = SHIFT[0];
            int r = SHIFT[1];
            int dir = SHIFT[2];
            delta[l] += 2 * dir - 1;
            delta[r + 1] -= 2 * dir - 1;
        }

        for(int i = 0; i < N; ++i){
            if(i > 0){
                delta[i] += delta[i - 1];
            }
            delta[i] = ((delta[i] % A) + A) % A;
            s[i] = char('a' + (s[i] - 'a' + delta[i]) % A);
        }

        return s;
    }
};