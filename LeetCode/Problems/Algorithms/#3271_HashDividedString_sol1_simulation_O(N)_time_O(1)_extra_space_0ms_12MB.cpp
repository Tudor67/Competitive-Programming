class Solution {
public:
    string stringHash(string s, int k) {
        const int N = s.length();

        string res(N / k, '#');
        for(int i = 0; i < N; i += k){
            int blockSum = 0;
            for(int j = i; j < i + k; ++j){
                blockSum += (s[j] - 'a');
            }
            res[i / k] = char('a' + blockSum % 26);
        }

        return res;
    }
};