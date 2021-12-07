class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        unordered_map<string, int> balance;
        for(const string& WORD: words1){
            balance[WORD] = min(1 + balance[WORD], 2);
        }
        
        for(const string& WORD: words2){
            if(balance.count(WORD) && balance[WORD] < 2){
                balance[WORD] -= 1;
            }
        }
        
        int answer = 0;
        for(const pair<string, int>& P: balance){
            if(P.second == 0){
                answer += 1;
            }
        }
        
        return answer;
    }
};