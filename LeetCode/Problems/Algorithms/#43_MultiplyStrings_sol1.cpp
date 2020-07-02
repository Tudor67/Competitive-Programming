class Solution {
private:
    void add(string& res_rev, const string& num_rev){
        int carry = 0;
        for(int i = 0; i < max(res_rev.length(), num_rev.length()); ++i){
            if(i >= res_rev.size()){
                res_rev.resize(i + 1, '0');
            }
            int digit1 = (i < res_rev.length() ? res_rev[i] - '0' : 0);
            int digit2 = (i < num_rev.length() ? num_rev[i] - '0' : 0);
            int sum = (digit1 + digit2 + carry);
            res_rev[i] = (char('0' + sum % 10));
            carry = sum / 10;
        }
        
        if(carry > 0){
            res_rev.push_back(char('0' + carry));
        }
    }
    
public:
    string multiply(string num1, string num2) {
        string num1_rev(num1.rbegin(), num1.rend());
        string num2_rev(num2.rbegin(), num2.rend());
        string res_rev;
        
        // multiply each digit of num2 with num1 and add all temporary results
        for(int j = 0; j < num2_rev.size(); ++j){
            int carry = 0;
            string temp(j, '0');
            
            for(int i = 0; i < num1_rev.size(); ++i){
                int sum = (num2_rev[j] - '0') * (num1_rev[i] - '0') + carry;
                temp.push_back(char('0' + sum % 10));
                carry = sum / 10;
            }
            
            if(carry > 0){
                temp.push_back(char('0' + carry));
            }
            
            add(res_rev, temp);
        }
        
        // remove leading zeros
        while(res_rev.size() > 1 && res_rev.back() == '0'){
            res_rev.pop_back();
        }
        
        return string(res_rev.rbegin(), res_rev.rend());
    }
};