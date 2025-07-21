class Solution {
public:
    string makeFancyString(string s) {
        const int N = s.length();

        string res;
        int l = 0;
        while(l < N){
            int r = l;
            while(r < N && s[l] == s[r]){
                r += 1;
            }
            res.append(min(2, r - l), s[l]);
            l = r;
        }

        return res;
    }
};