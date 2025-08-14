class Solution {
public:
    string largestGoodInteger(string num) {
        const int N = num.length();

        int maxGoodDigit = -1;

        int i = 0;
        while(i < N){
            int j = i + 1;
            while(j < N && num[i] == num[j]){
                j += 1;
            }
            if(j - i >= 3 && maxGoodDigit < num[i] - '0'){
                maxGoodDigit = num[i] - '0';
            }
            i = j;
        }

        if(maxGoodDigit >= 0){
            return string(3, maxGoodDigit + '0');
        }

        return "";
    }
};