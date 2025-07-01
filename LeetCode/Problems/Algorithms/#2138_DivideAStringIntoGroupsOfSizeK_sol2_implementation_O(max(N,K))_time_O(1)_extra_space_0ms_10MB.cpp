class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        const int N = s.length();
        const int G = (N + k - 1) / k;

        vector<string> res(G, string(k, fill));
        for(int i = 0; i < N; ++i){
            res[i / k][i % k] = s[i];
        }

        return res;
    }
};