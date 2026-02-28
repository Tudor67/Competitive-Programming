class Solution {
public:
    int numSteps(string s) {
        int steps = 0;
        int carry = 0;

        for(int i = (int)s.length() - 1; i >= 1; --i){
            if(s[i] == '0'){
                if(carry == 0){
                    steps += 1;
                }else{
                    steps += 2;
                }
            }else{
                if(carry == 0){
                    carry = 1;
                    steps += 2;
                }else{
                    steps += 1;
                }
            }
        }

        if(carry > 0){
            steps += 1;
        }

        return steps;
    }
};