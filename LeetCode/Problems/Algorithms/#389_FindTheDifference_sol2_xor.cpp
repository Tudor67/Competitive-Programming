class Solution {
public:
    char findTheDifference(string s, string t) {
        char answer = 0;
        for(char c: s){
            answer ^= c;
        }
        for(char c: t){
            answer ^= c;
        }
        return answer;
    }
};