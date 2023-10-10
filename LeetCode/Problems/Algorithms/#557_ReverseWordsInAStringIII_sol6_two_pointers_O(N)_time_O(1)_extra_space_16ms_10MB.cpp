class Solution {
public:
    string reverseWords(string s) {
        const int N = s.length();

        int l = 0;
        while(l < N){
            int r = l;
            while(r < N && s[r] != ' '){
                r += 1;
            }
            reverse(s.begin() + l, s.begin() + r);
            l = r + 1;
        }

        return s;
    }
};