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
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        const int W = words.size();
        const int P = puzzles.size();
        
        unordered_map<int, int> count;
        for(const string& WORD: words){
            int wordMask = stringToMask(WORD);
            if(__builtin_popcount((unsigned int)wordMask) <= 7){
                count[wordMask] += 1;
            }
        }
        
        vector<int> answer(P, 0);
        for(int i = 0; i < P; ++i){
            int puzzleMask = stringToMask(puzzles[i]);
            int fixedBit = puzzles[i][0] - 'a';
            int mask = puzzleMask ^ (1 << fixedBit);
            for(int submask = mask; submask >= 0; submask = (submask - 1) & mask){
                if(count.find(submask | (1 << fixedBit)) != count.end()){
                    answer[i] += count[submask | (1 << fixedBit)];
                }
                if(submask == 0){
                    break;
                }
            }
        }
        
        return answer;
    }
};