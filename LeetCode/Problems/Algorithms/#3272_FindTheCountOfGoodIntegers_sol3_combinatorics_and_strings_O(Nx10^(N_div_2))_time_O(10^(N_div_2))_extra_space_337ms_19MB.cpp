class Solution {
private:
    long long nCk(long long n, long long k){
        long long res = 1;
        for(int i = 1; i <= k; ++i){
            res *= (n - k + i);
            res /= i;
        }
        return res;
    }

public:
    long long countGoodIntegers(int n, int k) {
        using FreqArr10 = array<int, 10>;
        set<FreqArr10> normalizedKPalindromes;
        long long firstHalfStart = pow(10, (n - 1) / 2);
        long long firstHalfEnd = pow(10, (n - 1) / 2 + 1);

        for(long long firstHalf = firstHalfStart; firstHalf < firstHalfEnd; ++firstHalf){
            string s = to_string(firstHalf);
            s.resize(n, '0');
            for(int i = 0; i < n / 2; ++i){
                s[n - 1 - i] = s[i];
            }

            if(stoll(s) % k == 0){
                FreqArr10 freq{};
                for(char c: s){
                    freq[c - '0'] += 1;
                }
                normalizedKPalindromes.insert(freq);
            }
        }

        long long goodIntegers = 0;
        for(const FreqArr10& freq: normalizedKPalindromes){
            long long contrib = 1;
            int remPositions = n;

            contrib *= nCk(remPositions - 1, freq[0]);
            remPositions -= freq[0];

            for(int digit = 1; digit <= 9; ++digit){
                contrib *= nCk(remPositions, freq[digit]);
                remPositions -= freq[digit];
            }

            goodIntegers += contrib;
        }

        return goodIntegers;
    }
};