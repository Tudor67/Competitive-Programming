class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int wavinessSum = 0;
        for(int num = num1; num <= num2; ++num){
            string s = to_string(num);
            int len = s.length();
            for(int i = 1; i < len - 1; ++i){
                if((s[i - 1] < s[i] && s[i] > s[i + 1]) ||
                   (s[i - 1] > s[i] && s[i] < s[i + 1])){
                    ++wavinessSum;
                }
            }
        }
        return wavinessSum;
    }
};