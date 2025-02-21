class Solution {
private:
    int computePermutations(vector<int>& freq, vector<int>& factorial){
        int n = accumulate(freq.begin(), freq.end(), 0);
        int res = factorial[n];
        for(int i = 0; i < (int)freq.size(); ++i){
            res /= factorial[freq[i]];
        }
        return res;
    }

public:
    int numTilePossibilities(string tiles) {
        const int N = tiles.size();
        const int FULL_MASK = (1 << N) - 1;
        const int ALPHABET_SIZE = 26;
        const int FIRST_ELEM = 'A';

        set<vector<int>> vis;
        for(int mask = 1; mask <= FULL_MASK; ++mask){
            vector<int> freq(ALPHABET_SIZE);
            for(int bit = 0; bit < N; ++bit){
                if((mask >> bit) & 1){
                    freq[tiles[bit] - FIRST_ELEM] += 1;
                }
            }
            vis.insert(freq);
        }

        vector<int> factorial(N + 1, 1);
        for(int i = 2; i <= N; ++i){
            factorial[i] = factorial[i - 1] * i;
        }

        int distinctSeqs = 0;
        for(vector<int> currFreq: vis){
            distinctSeqs += computePermutations(currFreq, factorial);
        }

        return distinctSeqs;
    }
};