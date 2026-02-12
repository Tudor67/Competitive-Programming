class Solution {
public:
    int minimumDeletions(string s) {
        const int N = s.length();

        int bPrefCount = 0;
        int aSuffCount = count(s.begin(), s.end(), 'a');
        int minOps = min(aSuffCount, N - aSuffCount);

        for(int i = 0; i < N; ++i){
            bPrefCount += (int)(s[i] == 'b');
            aSuffCount -= (int)(s[i] == 'a');
            minOps = min(minOps, bPrefCount + aSuffCount);
        }

        return minOps;
    }
};