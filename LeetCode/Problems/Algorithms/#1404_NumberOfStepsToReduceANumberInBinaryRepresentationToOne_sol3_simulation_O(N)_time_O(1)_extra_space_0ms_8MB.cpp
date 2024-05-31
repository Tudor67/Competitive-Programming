class Solution {
public:
    int numSteps(string s) {
        const int N = s.length();

        int totalSteps = 0;
        int carry = 0;

        for(int i = N - 1; i >= 1; --i){
            int sum = (s[i] - '0') + carry;
            if(sum % 2 == 0){
                totalSteps += 1;
            }else{
                totalSteps += 2;
                carry = 1;
            }
        }

        totalSteps += carry;

        return totalSteps;
    }
};