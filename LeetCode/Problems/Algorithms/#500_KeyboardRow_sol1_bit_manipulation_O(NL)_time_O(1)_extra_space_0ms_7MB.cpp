class Solution {
private:
    int getCharMask(const string& S){
        int charMask = 0;
        for(char c: S){
            charMask |= (1 << (tolower(c) - 'a'));
        }
        return charMask;
    }

public:
    vector<string> findWords(vector<string>& words) {
        const int N = words.size();

        vector<int> rowCharMasks = {
            getCharMask("qwertyuiop"),
            getCharMask("asdfghjkl"),
            getCharMask("zxcvbnm")
        };

        vector<string> res;
        for(const string& WORD: words){
            int charMask = getCharMask(WORD);
            for(int rowCharMask: rowCharMasks){
                if((charMask | rowCharMask) == rowCharMask){
                    res.push_back(WORD);
                    break;
                }
            }
        }

        return res;
    }
};