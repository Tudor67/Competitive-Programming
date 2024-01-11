class Solution {
private:
    const int INF = 1e9;
    const int MAX_POW_OF_5 = 15625; // (5 ^ 6) = 15625,
                                    //           the max power of 5 that can be represented with 15 bits
                                    // 5 is a prime number => (5 ^ maxPow) % num == 0 <=> num is a power of 5

    bool isPowOf5(int num){
        return (MAX_POW_OF_5 % num == 0);
    }

    int computeMinPartitions(string& s, int startIndex, vector<int>& memo){
        const int N = s.length();

        if(startIndex == N){
            return 0;
        }

        if(s[startIndex] == '0'){
            return -1;
        }

        if(memo[startIndex] != INF){
            return memo[startIndex];
        }

        int res = -1;
        int num = 0;
        for(int i = startIndex; i < N; ++i){
            num = 2 * num + (s[i] - '0');
            int nextPartitions = computeMinPartitions(s, i + 1, memo);
            if(nextPartitions >= 0 && isPowOf5(num)){
                if(res == -1 || res > 1 + nextPartitions){
                    res = 1 + nextPartitions;
                }
            }
        }

        memo[startIndex] = res;
        return res;
    }

public:
    int minimumBeautifulSubstrings(string s) {
        const int N = s.length();
        vector<int> memo(N, INF);
        return computeMinPartitions(s, 0, memo);
    }
};