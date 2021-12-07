class Solution {
private:
    void countWords(vector<string>& words, unordered_map<string, int>& count){
        count.clear();
        for(const string& WORD: words){
            count[WORD] += 1;
        }
    }
    
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        unordered_map<string, int> count1;
        unordered_map<string, int> count2;
        
        countWords(words1, count1);
        countWords(words2, count2);
        
        int answer = 0;
        for(const pair<string, int>& P: count1){
            const string& WORD = P.first;
            if(count1[WORD] == 1 && count2.count(WORD) && count2[WORD] == 1){
                answer += 1;
            }
        }
        
        return answer;
    }
};