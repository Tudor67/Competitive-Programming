class Solution {
public:
    int numberOfSubstrings(string s) {
        const int N = s.length();

        vector<int> suffSum(N + 1);
        for(int i = N - 1; i >= 0; --i){
            suffSum[i] = (s[i] - '0') + suffSum[i + 1];
        }

        vector<int> nextZero(N);
        for(int i = N - 1; i >= 0; --i){
            if(i + 1 == N || s[i + 1] == '0'){
                nextZero[i] = i + 1;
            }else{
                nextZero[i] = nextZero[i + 1];
            }
        }

        int res = 0;
        for(int i = 0; i < N; ++i){
            int j = i;
            while(j < N){
                int ones = suffSum[i] - suffSum[j + 1];
                int zeros = j - i + 1 - ones;
                if(ones >= zeros * zeros){
                    res += (nextZero[j] - j);
                    j = nextZero[j];
                }else{
                    j += (zeros * zeros - ones);
                }
            }
        }

        return res;
    }
};