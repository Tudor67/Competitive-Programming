class Solution {
public:
    int numSteps(string s) {
        int totalSteps = 0;
        
        while((int)s.size() >= 2){
            totalSteps += 1;
            if(s.back() == '0'){
                s.pop_back();
            }else{
                int carry = 1;
                for(int i = (int)s.length() - 1; i >= 0 && carry > 0; --i){
                    int sum = (s[i] - '0') + carry;
                    s[i] = char('0' + (sum % 2));
                    carry = sum / 2;
                }
                if(carry > 0){
                    s.insert(s.begin(), '1');
                }
            }
        }

        return totalSteps;
    }
};