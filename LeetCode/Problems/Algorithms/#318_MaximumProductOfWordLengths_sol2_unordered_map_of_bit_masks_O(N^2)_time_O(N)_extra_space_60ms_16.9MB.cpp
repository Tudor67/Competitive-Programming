class Solution {
private:
    int wordToMask(const string& WORD){
        int mask = 0;
        for(char c: WORD){
            mask |= (1 << (c - 'a'));
        }
        return mask;
    }
    
public:
    int maxProduct(vector<string>& words) {
        unordered_map<int, int> maxLen;
        for(const string& WORD: words){
            int mask = wordToMask(WORD);
            maxLen[mask] = max((int)WORD.length(), maxLen[mask]);
        }
        
        int answer = 0;
        for(const pair<int, int>& P1: maxLen){
            int mask1 = P1.first;
            int len1 = P1.second;
            for(const pair<int, int>& P2: maxLen){
                int mask2 = P2.first;
                int len2 = P2.second;
                if((mask1 & mask2) == 0){
                    answer = max(len1 * len2, answer);
                }
            }
        }
        
        return answer;
    }
};