class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        const int N = words.size();
        
        unordered_map<string, int> count;
        for(const string& WORD: words){
            count[WORD] += 1;
        }
        
        int answer = 0;
        int extra = 0;
        for(const string& WORD: words){
            const string WORD_REV(WORD.rbegin(), WORD.rend());
            if(count[WORD] == 0){
                continue;
            }
            count[WORD] -= 1;
            if(count.count(WORD_REV) && count[WORD_REV] >= 1){
                count[WORD_REV] -= 1;
                answer += 4;
            }else{
                if(WORD == WORD_REV){
                    extra = 2;
                }
            }
        }
        
        answer += extra;
        
        return answer;
    }
};