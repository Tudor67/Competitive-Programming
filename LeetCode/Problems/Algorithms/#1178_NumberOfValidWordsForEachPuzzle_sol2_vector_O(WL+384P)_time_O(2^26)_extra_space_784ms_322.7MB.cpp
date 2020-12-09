class Solution {
private:
    int stringToMask(const string& WORD){
        int mask = 0;
        for(char c: WORD){
            mask |= (1 << (c - 'a'));
        }
        return mask;
    }
    
public:
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        vector<int> count(1 << 26);
        for(const string& WORD: words){
            int stringMask = stringToMask(WORD);
            count[stringMask] += 1;
        }
        
        vector<int> answer(puzzles.size(), 0);
        for(int i = 0; i < puzzles.size(); ++i){
            const int FIXED_BIT = puzzles[i][0] - 'a';
            for(int mask = 0; mask < (1 << 6); ++mask){
                int stringMask = (1 << FIXED_BIT);
                for(int bit = 0; bit < 6; ++bit){
                    if((mask >> bit) & 1){
                        stringMask |= (1 << (puzzles[i][bit + 1] - 'a'));
                    }
                }
                answer[i] += count[stringMask];
            }
        }
        
        return answer;
    }
};