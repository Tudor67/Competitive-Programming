class Solution {
public:
    int minFlips(string s) {
        const int N = s.length();

        int minOps = N;
        vector<int> currOps(2);
        
        for(int i = 0; i < 2 * N - 1; ++i){
            if(i < N){
                currOps[i % 2] += (s[i] - '0') % 2 != (i % 2);
            }else{
                currOps[0] -= (s[i - N] - '0') % 2 != (0 % 2);
                currOps[0] = (N - 1) / 2 - currOps[0];
                currOps[1] = N / 2 - currOps[1];
                currOps[(N - 1) % 2] += (s[i - N] - '0') % 2 != ((N - 1) % 2);
            }

            if(i >= N - 1){
                int ops01 = currOps[0] + currOps[1];
                int ops10 = N - ops01;
                minOps = min(minOps, min(ops01, ops10));
            }
        }

        return minOps;
    }
};