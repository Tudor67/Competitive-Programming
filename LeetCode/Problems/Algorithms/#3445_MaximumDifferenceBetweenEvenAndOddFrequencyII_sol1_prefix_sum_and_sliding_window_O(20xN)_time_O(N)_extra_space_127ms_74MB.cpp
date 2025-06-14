class Solution {
private:
    const int INF = 1e9;

    int computeMaxDiff(string& s, int k, char c0, char c1){
        const int N = s.length();

        vector<int> status(N);
        vector<int> prefSum(N);
        for(int i = 0; i < N; ++i){
            if(i > 0){
                status[i] = status[i - 1];
                prefSum[i] = prefSum[i - 1];
            }
            if(s[i] == c0){
                status[i] ^= 1;
                prefSum[i] -= 1;
            }else if(s[i] == c1){
                status[i] ^= 2;
                prefSum[i] += 1;
            }
        }

        int maxDiff = -INF;
        vector<int> minDiff(4, INF);
        minDiff[0] = 0;

        int l = 0;
        int wCount0 = 0;
        for(int r = 0; r < N; ++r){
            wCount0 += (int)(s[r] == c0);
            while(r - l + 1 > k && wCount0 - (int)(s[l] == c0) >= 2){
                minDiff[status[l]] = min(minDiff[status[l]], prefSum[l]);
                wCount0 -= (int)(s[l] == c0);
                l += 1;
            }

            if(r >= k - 1 && wCount0 >= 2){
                int complStatus = status[r] ^ 2;
                maxDiff = max(maxDiff, prefSum[r] - minDiff[complStatus]);
            }
        }

        return maxDiff;
    }

public:
    int maxDifference(string s, int k) {
        int maxDiff = -INF;
        for(char c0 = '0'; c0 <= '4'; ++c0){
            for(char c1 = '0'; c1 <= '4'; ++c1){
                if(c0 != c1){
                    maxDiff = max(maxDiff, computeMaxDiff(s, k, c0, c1));
                }
            }
        }
        return maxDiff;
    }
};