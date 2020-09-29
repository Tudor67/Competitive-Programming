class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> charCount(128, 0);
        for(char c: s){
            charCount[c] += 1;
        }
        
        char answer;
        for(char c: t){
            charCount[c] -= 1;
            if(charCount[c] < 0){
                answer = c;
                break;
            }
        }
        
        return answer;
    }
};