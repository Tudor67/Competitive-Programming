class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> answer;
        for(int len = 1; len <= 9; ++len){
            for(int startDigit = 1; startDigit + len - 1 <= 9; ++startDigit){
                int endDigit = startDigit + len - 1;
                int num = 0;
                for(int digit = startDigit; digit <= endDigit; ++digit){
                    num = 10 * num + digit;
                }
                if(low <= num && num <= high){
                    answer.push_back(num);
                }
            }
        }
        return answer;
    }
};