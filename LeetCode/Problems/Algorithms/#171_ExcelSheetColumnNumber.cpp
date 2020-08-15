class Solution {
public:
    int titleToNumber(string s) {
        int answer = 0;
        for(char c: s){
            answer = answer * 26 + (c - 'A' + 1);
        }
        return answer;
    }
};