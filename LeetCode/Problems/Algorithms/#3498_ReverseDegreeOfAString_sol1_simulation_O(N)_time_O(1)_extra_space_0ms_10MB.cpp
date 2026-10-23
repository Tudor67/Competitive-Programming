class Solution {
public:
    int reverseDegree(string s) {
        const int N = s.length();

        int res = 0;
        for(int i = 0; i < N; ++i){
            res += (i + 1) * ('z' - s[i] + 1);
        }

        return res;
    }
};