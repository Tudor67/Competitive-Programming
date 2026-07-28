class Solution {
public:
    string smallestPalindrome(string s) {
        const int N = s.length();
        const int A = 26;

        vector<int> freq(A);
        for(char c: s){
            freq[c - 'a'] += 1;
        }

        string res(N, '$');
        int resIndex = 0;
        for(char c = 'a'; c <= 'z'; ++c){
            while(freq[c - 'a'] >= 2){
                freq[c - 'a'] -= 2;
                res[resIndex] = c;
                res[N - 1 - resIndex] = c;
                resIndex += 1;
            }
            if(freq[c - 'a'] == 1){
                freq[c - 'a'] -= 1;
                res[N / 2] = c;
            }
        }

        return res;
    }
};