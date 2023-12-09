class Solution {
public:
    string largestGoodInteger(string num) {
        const int N = num.length();
        
        int maxGoodDigit = -1;
        for(int i = 0; i + 2 < N; ++i){
            if(num[i] == num[i + 1] && num[i + 1] == num[i + 2]){
                maxGoodDigit = max(maxGoodDigit, num[i] - '0');
            }
        }

        if(maxGoodDigit == -1){
            return "";
        }
        
        return string(3, maxGoodDigit + '0');
    }
};