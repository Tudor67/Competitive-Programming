class Solution {
private:
    int getWordMask(const string& WORD){
        int mask = 0;
        for(char c: WORD){
            mask |= (1 << (c - 'a'));
        }
        return mask;
    }
    
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int count = 0;
        int allowedMask = getWordMask(allowed);
        int forbiddenMask = ~allowedMask;
        for(const string& WORD: words){
            int wordMask = getWordMask(WORD);
            if(!(forbiddenMask & wordMask)){
                count += 1;
            }
        }
        return count;
    }
};