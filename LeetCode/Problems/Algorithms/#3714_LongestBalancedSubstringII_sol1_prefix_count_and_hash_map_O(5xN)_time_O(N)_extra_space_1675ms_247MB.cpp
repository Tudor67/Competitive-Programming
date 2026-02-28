class Solution {
public:
    int longestBalanced(string s) {
        const int N = s.length();

        int maxLen = 0;

        // Case 1: check substrings with 1 distinct char
        int currLen = 0;
        for(int i = 0; i < N; ++i){
            if(i > 0 && s[i - 1] == s[i]){
                currLen += 1;
            }else{
                currLen = 1;
            }
            maxLen = max(maxLen, currLen);
        }

        // Case 2: check substrings with 2 distinct chars
        for(char c1 = 'a'; c1 <= 'b'; ++c1){
            for(char c2 = c1 + 1; c2 <= 'c'; ++c2){
                int balance = 0;
                unordered_map<int, int> firstIndexOf;
                firstIndexOf[0] = -1;

                for(int i = 0; i < N; ++i){
                    if(s[i] != c1 && s[i] != c2){
                        balance = 0;
                        firstIndexOf.clear();
                        firstIndexOf[0] = i;
                    }else{
                        balance += (s[i] == c1 ? -1 : 1);
                        if(firstIndexOf.count(balance)){
                            maxLen = max(maxLen, i - firstIndexOf[balance]);
                        }else{
                            firstIndexOf[balance] = i;
                        }
                    }
                }
            }
        }

        // Case 3: check substrings with 3 distinct chars
        const long long MULT_COEF = 5e5;
        vector<int> prefCount(3);
        unordered_map<long long, int> firstIndexOf;
        firstIndexOf[N * MULT_COEF + N] = -1;

        for(int i = 0; i < N; ++i){
            prefCount[s[i] - 'a'] += 1;
            long long delta = (prefCount[0] - prefCount[1] + N) * MULT_COEF + (prefCount[1] - prefCount[2] + N);
            if(firstIndexOf.count(delta)){
                maxLen = max(maxLen, i - firstIndexOf[delta]);
            }else{
                firstIndexOf[delta] = i;
            }
        }

        return maxLen;
    }
};