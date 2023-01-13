class Solution {
public:
    int secondHighest(string s) {
        const int N = s.length();

        char firstMax = '0' - 1;
        char secondMax = '0' - 1;
        for(char c: s){
            if(isdigit(c)){
                if(c > firstMax){
                    secondMax = firstMax;
                    firstMax = c;
                }else if(c > secondMax && c < firstMax){
                    secondMax = c;
                }
            }
        }

        if(secondMax >= '0'){
            return secondMax - '0';
        }
        return -1;
    }
};