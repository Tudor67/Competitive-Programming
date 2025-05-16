class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        const int N = s.length();
        const int MODULO = 1'000'000'007;
        const int ALPHABET_SIZE = 26;

        vector<int> currFreq(ALPHABET_SIZE);
        vector<int> nextFreq(ALPHABET_SIZE);
        for(char c: s){
            currFreq[c - 'a'] += 1;
        }

        for(int step = 1; step <= t; ++step){
            fill(nextFreq.begin(), nextFreq.end(), 0);
            for(char c = 'b'; c <= 'z'; ++c){
                nextFreq[c - 'a'] = (nextFreq[c - 'a'] + currFreq[c - 'a' - 1]) % MODULO;
            }
            nextFreq['a' - 'a'] = (nextFreq['a' - 'a'] + currFreq['z' - 'a']) % MODULO;
            nextFreq['b' - 'a'] = (nextFreq['b' - 'a'] + currFreq['z' - 'a']) % MODULO;
            copy(nextFreq.begin(), nextFreq.end(), currFreq.begin());
        }

        return accumulate(currFreq.begin(), currFreq.end(), (long long)0) % MODULO;
    }
};