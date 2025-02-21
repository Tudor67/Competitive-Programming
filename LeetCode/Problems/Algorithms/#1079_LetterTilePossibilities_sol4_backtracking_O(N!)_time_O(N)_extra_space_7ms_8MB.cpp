class Solution {
private:
    const int ALPHABET_SIZE = 26;
    const int FIRST_ELEM = 'A';

    void back(vector<int>& freq, int& distinctSeqs){
        for(int elem = 0; elem < ALPHABET_SIZE; ++elem){
            if(freq[elem] >= 1){
                distinctSeqs += 1;
                freq[elem] -= 1;
                back(freq, distinctSeqs);
                freq[elem] += 1;
            }
        }
    }

public:
    int numTilePossibilities(string tiles) {
        vector<int> freq(ALPHABET_SIZE);
        for(char c: tiles){
            freq[c - FIRST_ELEM] += 1;
        }

        int distinctSeqs = 0;
        back(freq, distinctSeqs);

        return distinctSeqs;
    }
};