class Solution {
public:
    int minimumDeletions(string s) {
        const int N = s.length();

        int aTotalCount = count(s.begin(), s.end(), 'a');
        int bTotalCount = N - bTotalCount;

        int res = min(aTotalCount, bTotalCount);
        int bPrefCount = 0;
        int aSuffCount = aTotalCount;
        for(int i = 0; i < N; ++i){
            bPrefCount += (int)(s[i] == 'b');
            aSuffCount -= (int)(s[i] == 'a');
            res = min(res, bPrefCount + aSuffCount);
        }

        return res;
    }
};