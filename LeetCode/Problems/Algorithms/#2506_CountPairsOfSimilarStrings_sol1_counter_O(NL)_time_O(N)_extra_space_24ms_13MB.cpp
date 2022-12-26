class Solution {
private:
    int getCharMask(const string& WORD){
        int charMask = 0;
        for(char c: WORD){
            charMask |= (1 << (c - 'a'));
        }
        return charMask;
    }

public:
    int similarPairs(vector<string>& words) {
        const int N = words.size();

        int validPairs = 0;
        unordered_map<int, int> count;
        for(const string& WORD: words){
            int charMask = getCharMask(WORD);
            validPairs += count[charMask];
            count[charMask] += 1;
        }

        return validPairs;
    }
};