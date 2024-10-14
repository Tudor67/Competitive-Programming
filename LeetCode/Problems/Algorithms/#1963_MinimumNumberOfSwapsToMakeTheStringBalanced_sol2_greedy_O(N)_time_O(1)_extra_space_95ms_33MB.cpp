class Solution {
public:
    int minSwaps(string s) {
        int openBrackets = 0;
        for(char c: s){
            if(c == '['){
                openBrackets += 1;
            }else if(openBrackets >= 1){
                openBrackets -= 1;
            }
        }
        return (openBrackets + 1) / 2;
    }
};