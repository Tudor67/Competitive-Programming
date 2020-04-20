class Solution {
private:
    string get_sum(string& a, string& b){
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        string sum;
        
        int carry = 0;
        for(int i = 0; i < max(a.length(), b.length()); ++i){
            int a_digit = (i < a.length() ? a[i] - '0' : 0);
            int b_digit = (i < b.length() ? b[i] - '0' : 0);
            int s = (carry + a_digit + b_digit);
            sum.push_back(char(s % 10 + '0'));
            carry = s / 10;
        }
        
        if(carry > 0){
            sum.push_back(char(carry + '0'));
        }
        
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        reverse(sum.begin(), sum.end());
        
        return sum;
    }
    
    bool has_leading_zeros(const string& s){
        return (s.length() > 1 && s[0] == '0');
    }
    
    bool seq_match(const string& s1, const string& s2, const int& s2_start_pos){
        bool ok = (s2_start_pos + s1.length() - 1 < s2.length());
        for(int i = 0; i < s1.length(); ++i){
            ok = ok && (s1[i] == (s2[s2_start_pos + i]));
        }
        return ok;
    }
    
public:
    bool isAdditiveNumber(string num) {
        string S = num;
        int n = S.length();
        bool is_additive = false;
        
        if(n >= 3){
            for(int i = 1; i <= min(18, n); ++i){
                for(int j = 1; !is_additive && j <= min(18, n) && i + j - 1 < n; ++j){
                    string a = S.substr(0, i);
                    string b = S.substr(i, j);
                    
                    if(!has_leading_zeros(a) && !has_leading_zeros(b)){
                        int last_pos = a.length() + b.length();
                        int fib_length = 2;
                        while(last_pos < n){
                            string c = get_sum(a, b);
                            if(!has_leading_zeros(c) && seq_match(c, S, last_pos)){
                                a = b;
                                b = c;
                                fib_length += 1;
                                last_pos += c.length();
                            }else{
                                last_pos = n + 10;
                            }
                        }
                        
                        if(last_pos == n && fib_length >= 3){
                            is_additive = true;
                        }
                    }
                }
            }
        }
        
        return is_additive;
    }
};