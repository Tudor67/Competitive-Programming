class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        if(s.length() < words.size() * words[0].length()){
            return {};
        }
        
        // Step 1: word to idx
        map<string, int> idxOf;
        int wordIdx = 0;
        for(const string& WORD: words){
            if(!idxOf.count(WORD)){
                idxOf[WORD] = wordIdx;
                wordIdx += 1;
            }
        }
        
        // Step 2: count word indices == count words
        const int DISTINCT_WORDS = wordIdx;
        vector<int> expectedCnt(DISTINCT_WORDS, 0);
        for(const string& WORD: words){
            expectedCnt[idxOf[WORD]] += 1;
        }
        
        // Step 3: compute matchIdx[i] = idxOf[s.substr(i, WORD_LENGTH)]
        const int WORD_LENGTH = words[0].length();
        vector<int> matchIdx(s.length(), -1);
        for(int i = 0; i + WORD_LENGTH - 1 < s.length(); ++i){
            string word = s.substr(i, WORD_LENGTH);
            matchIdx[i] = (idxOf.count(word) ? idxOf[word] : -1);
        }
        
        // Step 4: sliding window on matchIdx
        vector<int> answer;
        vector<int> cnt(expectedCnt.size());
        int expectedChars = words.size() * words[0].length();
        for(int i = 0, j = expectedChars - 1; j < s.length(); ++i, ++j){
            fill(cnt.begin(), cnt.end(), 0);
            for(int k = i; k <= j; k += WORD_LENGTH){
                if(matchIdx[k] >= 0){
                    cnt[matchIdx[k]] += 1;
                }
            }
            if(cnt == expectedCnt){
                answer.push_back(i);
            }
        }
        
        return answer;
    }
};