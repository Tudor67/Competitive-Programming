class Solution {
private:
    long long nCk(long long n, long long k){
        long long res = 1;
        for(long long i = 1; i <= k; ++i){
            res *= (n - k + i);
            res /= i;
        }
        return res;
    }

public:
    long long countGoodIntegers(int n, int k) {
        string startHalfStr = "1" + string((n - 1) / 2, '0');
        string endHalfStr   = "9" + string((n - 1) / 2, '9');

        long long startHalf = stoll(startHalfStr);
        long long endHalf   = stoll(endHalfStr);

        using FreqArray = array<int, 10>;
        set<FreqArray> goodSet;
        for(long long h = startHalf; h <= endHalf; ++h){
            string s = to_string(h);
            s.resize(n, '0');
            copy(s.begin(), s.end(), s.rbegin());

            if(stoll(s) % k == 0){
                FreqArray digitFreq;
                fill(digitFreq.begin(), digitFreq.end(), 0);
                for(char c: s){
                    digitFreq[c - '0'] += 1;
                }
                goodSet.insert(digitFreq);
            }
        }

        long long goodIntegers = 0;
        for(const FreqArray& digitFreq: goodSet){
            long long contrib = nCk(n - 1, digitFreq[0]);
            int remPlaces = n - digitFreq[0];
            for(int digit = 1; digit <= 9; ++digit){
                contrib *= nCk(remPlaces, digitFreq[digit]);
                remPlaces -= digitFreq[digit];
            }
            goodIntegers += contrib;
        }

        return goodIntegers;
    }
};