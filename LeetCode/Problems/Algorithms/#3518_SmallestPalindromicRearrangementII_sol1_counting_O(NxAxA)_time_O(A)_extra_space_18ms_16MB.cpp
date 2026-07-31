class Solution {
private:
    int nCk(int n, int k){
        k = min(k, n - k);
        long long res = 1;
        for(int i = 1; i <= k; ++i){
            res *= (n - k + i);
            res /= i;
            if(res >= INT_MAX){
                res = INT_MAX;
                break;
            }
        }
        return res;
    }

    int countDistinctPermutations(vector<int>& freq){
        int distinctPermutations = 1;
        int n = accumulate(freq.begin(), freq.end(), 0);
        for(int k: freq){
            int combinations = nCk(n, k);
            if(distinctPermutations < INT_MAX / combinations){
                distinctPermutations *= combinations;
                n -= k;
            }else{
                distinctPermutations = INT_MAX;
                break;
            }
        }
        return distinctPermutations;
    }

public:
    string smallestPalindrome(string s, int k) {
        const int N = s.length();
        const int A = 26;

        vector<int> freq(A);
        for(int i = 0; i < N / 2; ++i){
            freq[s[i] - 'a'] += 1;
        }

        if(countDistinctPermutations(freq) < k){
            return "";
        }

        string res(N, '$');
        for(int i = 0; i < N / 2; ++i){
            for(char c = 'a'; c <= 'z'; ++c){
                if(freq[c - 'a'] >= 1){
                    freq[c - 'a'] -= 1;
                    int distinctPermutations = countDistinctPermutations(freq);
                    if(k > distinctPermutations){
                        k -= distinctPermutations;
                        freq[c - 'a'] += 1;
                    }else{
                        res[i] = c;
                        break;
                    }
                }
            }
        }

        for(int i = 0; i < N / 2; ++i){
            res[N - 1 - i] = res[i];
        }

        if(N % 2 == 1){
            res[N / 2] = s[N / 2];
        }

        return res;
    }
};