class Solution {
private:
    const int A = 26;
    const int FIRST_CHAR = 'a';
    
    void updateCount(const string& WORD, vector<int>& count){
        fill(count.begin(), count.end(), 0);
        for(char c: WORD){
            count[c - FIRST_CHAR] += 1;
        }
    }
    
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> words2MaxCount(A);
        vector<int> count(A);
        for(const string& WORD2: words2){
            updateCount(WORD2, count);
            for(int c = FIRST_CHAR; c < FIRST_CHAR + A; ++c){
                words2MaxCount[c - FIRST_CHAR] = max(words2MaxCount[c - FIRST_CHAR], count[c - FIRST_CHAR]);
            }
        }
        
        vector<string> universalStrings;
        for(const string& WORD1: words1){
            updateCount(WORD1, count);
            bool isUniversal = true;
            for(int c = FIRST_CHAR; c < FIRST_CHAR + A; ++c){
                if(count[c - FIRST_CHAR] < words2MaxCount[c - FIRST_CHAR]){
                    isUniversal = false;
                    break;
                }
            }
            if(isUniversal){
                universalStrings.push_back(WORD1);
            }
        }
        
        return universalStrings;
    }
};