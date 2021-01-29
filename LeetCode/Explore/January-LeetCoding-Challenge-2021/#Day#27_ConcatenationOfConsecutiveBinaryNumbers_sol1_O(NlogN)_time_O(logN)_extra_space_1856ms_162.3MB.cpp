class Solution {
public:
    int concatenatedBinary(int n) {
        const int MODULO = 1e9 + 7;
        int answer = 0;
        for(int i = 1; i <= n; ++i){
            int num = i;
            string binaryRepr;
            while(num > 0){
                binaryRepr += string(1, num % 2 + '0');
                num /= 2;
            }
            for(int j = (int)binaryRepr.size() - 1; j >= 0; --j){
                answer = (2 * answer + binaryRepr[j] - '0');
                if(answer >= MODULO){
                    answer -= MODULO;
                }
            }
        }
        return answer;
    }
};