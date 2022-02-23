class Solution {
public:
    string reverseStr(string s, int k) {
        const int N = s.length();
        for(int i = 0; i < N; i += 2 * k){
            reverse(s.begin() + i, s.begin() + min(i + k, N));
        }
        return s;
    }
};