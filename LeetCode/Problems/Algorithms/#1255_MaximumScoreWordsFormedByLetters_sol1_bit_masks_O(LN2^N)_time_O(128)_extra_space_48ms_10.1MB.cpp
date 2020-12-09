class Solution {
private:
    const int MIN_CHAR = 'a';
    const int MAX_CHAR = 'z';
    
    void updateCount(const int& MASK, const vector<string>& WORDS, vector<int>& count){
        const int N = WORDS.size();
        fill(count.begin() + MIN_CHAR, count.end(), 0);
        for(int bit = 0; bit < N; ++bit){
            if((MASK >> bit) & 1){
                for(char c: WORDS[bit]){
                    count[c] += 1;
                }
            }
        }
    }
    
    bool isValid(const vector<int>& COUNT, const vector<int>& MAX_COUNT){
        for(int c = MIN_CHAR; c <= MAX_CHAR; ++c){
            if(COUNT[c] > MAX_COUNT[c]){
                return false;
            }
        }
        return true;
    }
    
    int getScore(const int& MASK, const vector<string>& WORDS, const vector<int>& SCORES){
        const int N = WORDS.size();
        int score = 0;
        for(int bit = 0; bit < N; ++bit){
            if((MASK >> bit) & 1){
                for(char c: WORDS[bit]){
                    score += SCORES[c - MIN_CHAR];
                }
            }
        }
        return score;
    }
    
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& scores) {        
        const int N = words.size();
        const int FULL_MASK = (1 << N) - 1;
        
        vector<int> count(MAX_CHAR + 1);
        vector<int> maxCount(MAX_CHAR + 1);
        for(char c: letters){
            maxCount[c] += 1;
        }
        
        int answer = 0;
        for(int mask = 0; mask <= FULL_MASK; ++mask){
            updateCount(mask, words, count);
            if(isValid(count, maxCount)){
                int currentScore = getScore(mask, words, scores);
                answer = max(currentScore, answer);
            }
        }
        
        return answer;
    }
};