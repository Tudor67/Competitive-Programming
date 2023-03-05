class Solution {
public:
    int minMaxDifference(int num) {
        string numStr = to_string(num);

        char firstNon9 = '9';
        for(int i = 0; i < (int)numStr.length(); ++i){
            if(numStr[i] != '9'){
                firstNon9 = numStr[i];
                break;
            }
        }

        char minSwapChar = numStr[0];
        char maxSwapChar = firstNon9;
        int minNum = 0;
        int maxNum = 0;

        for(char c: numStr){
            if(c == minSwapChar){
                minNum = minNum * 10 + 0;
            }else{
                minNum = minNum * 10 + (c - '0');
            }

            if(c == maxSwapChar){
                maxNum = maxNum * 10 + 9;
            }else{
                maxNum = maxNum * 10 + (c - '0');
            }
        }
        
        return maxNum - minNum;
    }
};