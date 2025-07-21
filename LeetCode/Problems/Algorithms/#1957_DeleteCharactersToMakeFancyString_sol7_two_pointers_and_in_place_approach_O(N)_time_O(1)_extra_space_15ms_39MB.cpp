class Solution {
public:
    string makeFancyString(string s) {
        const int N = s.length();

        int resLen = 0;
        int l = 0;
        while(l < N){
            int r = l;
            while(r < N && s[l] == s[r]){
                r += 1;
            }

            int minCons = min(2, r - l);
            fill(s.begin() + resLen, s.begin() + resLen + minCons, s[l]);
            resLen += minCons;
            
            l = r;
        }

        s.resize(resLen);

        return s;
    }
};