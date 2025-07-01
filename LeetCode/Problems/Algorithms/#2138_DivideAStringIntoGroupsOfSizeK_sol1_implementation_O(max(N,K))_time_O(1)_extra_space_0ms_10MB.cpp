class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        const int N = s.length();
        const int G = (N + k - 1) / k;

        vector<string> res(G);
        for(int i = 0; i < N; ++i){
            res[i / k] += s[i];
        }

        res.back().resize(k, fill);

        return res;
    }
};