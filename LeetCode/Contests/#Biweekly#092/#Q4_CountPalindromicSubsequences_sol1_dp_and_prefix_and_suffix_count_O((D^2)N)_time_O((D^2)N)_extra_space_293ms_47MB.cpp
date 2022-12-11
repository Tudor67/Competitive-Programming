class Solution {
public:
    int countPalindromes(string s) {
        const int N = s.length();
        const int MODULO = 1e9 + 7;

        // digitPrefCount[a]: count of digit a in s[0 .. i]
        vector<vector<int>> digitPrefCount(10, vector<int>(N));
        for(int i = 0; i < N; ++i){
            digitPrefCount[s[i] - '0'][i] += 1;
            if(i >= 1){
                for(int digit = 0; digit < 10; ++digit){
                    digitPrefCount[digit][i] += digitPrefCount[digit][i - 1];
                }
            }
        }

        // pairsPrefCount[ab][i]: number of pairs (a, b) in s[0 .. i]
        //                        a is a digit from 0 to 9
        //                        b is a digit from 0 to 9
        vector<vector<int>> pairsPrefCount(100, vector<int>(N));
        for(int i = 1; i < N; ++i){
            int b = s[i] - '0';
            for(int a = 0; a < 10; ++a){
                pairsPrefCount[a * 10 + b][i] += digitPrefCount[a][i - 1];
            }
            for(int ab = 0; ab < 100; ++ab){
                pairsPrefCount[ab][i] += pairsPrefCount[ab][i - 1];
            }
        }
        
        // revPairsSuffCount[ab][i]: number of pairs (b, a) in s[i .. N - 1]
        //                           a is a digit from 0 to 9
        //                           b is a digit from 0 to 9
        vector<vector<int>> revPairsSuffCount(100, vector<int>(N));
        for(int i = N - 2; i >= 0; --i){
            int b = s[i] - '0';
            for(int a = 0; a < 10; ++a){
                revPairsSuffCount[a * 10 + b][i] += digitPrefCount[a][N - 1] - digitPrefCount[a][i];
            }
            for(int ab = 0; ab < 100; ++ab){
                revPairsSuffCount[ab][i] += revPairsSuffCount[ab][i + 1];
            }
        }

        long long res = 0;
        for(int i = 2; i + 2 < N; ++i){
            // fix center s[i]
            // palindrome ab + s[i] + ba
            for(int ab = 0; ab < 100; ++ab){
                res += (long long)pairsPrefCount[ab][i - 1] * (long long)revPairsSuffCount[ab][i + 1];
                res %= MODULO;
            }
        }
        
        return res;
    }
};