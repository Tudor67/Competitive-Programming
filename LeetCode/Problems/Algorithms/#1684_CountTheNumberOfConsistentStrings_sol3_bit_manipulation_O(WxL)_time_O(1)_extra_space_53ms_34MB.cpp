class Solution {
private:
    int stringToMask(const string& S){
        int mask = 0;
        for(char c: S){
            mask |= (1 << (c - 'a'));
        }
        return mask;
    }

public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int consistentStrings = 0;

        int forbiddenMask = ~stringToMask(allowed);

        for(const string& WORD: words){
            if((forbiddenMask & stringToMask(WORD)) == 0){
                consistentStrings += 1;
            }
        }
        
        return consistentStrings;
    }
};