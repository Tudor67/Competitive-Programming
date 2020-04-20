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
    
    int string_to_int(const string& s){
        int num = 0;
        for(char c: s){
            num = num * 10 + (c - '0');
        }
        return num;
    }
    
    bool valid(const string& s){
        bool has_leading_zeros = (s.length() > 1 && s[0] == '0');
        bool is_32_bit_int;
        
        if(s.size() == 10){
            is_32_bit_int = (s <= "2147483647");
        }else{
            is_32_bit_int = (s.size() < 10);
        }
        
        return (!has_leading_zeros && is_32_bit_int);
    }
    
    bool seq_match(const string& s1, const string& s2, const int& s2_start_pos){
        bool ok = (s2_start_pos + s1.length() - 1 < s2.length());
        for(int i = 0; i < s1.length(); ++i){
            ok = ok && (s1[i] == (s2[s2_start_pos + i]));
        }
        return ok;
    }
    
public:
    vector<int> splitIntoFibonacci(string S) {
        int n = S.length();
        vector<int> ans;
        vector<int> split_positions;
        
        if(n >= 3){
            for(int i = 1; i <= min(10, n); ++i){
                for(int j = 1; ans.empty() && j <= min(10, n) && i + j - 1 < n; ++j){
                    string a = S.substr(0, i);
                    string b = S.substr(i, j);
                    
                    if(valid(a) && valid(b)){
                        split_positions.clear();
                        split_positions.push_back(0);
                        split_positions.push_back(i);
                        split_positions.push_back(i + j);
                        
                        int last_pos = a.length() + b.length();
                        int fib_length = 2;
                        while(last_pos < n){
                            string c = get_sum(a, b);
                            if(valid(c) && seq_match(c, S, last_pos)){
                                a = b;
                                b = c;
                                fib_length += 1;
                                last_pos += c.length();
                                split_positions.push_back(last_pos);
                            }else{
                                last_pos = n + 10;
                            }
                        }
                        
                        if(last_pos == n && fib_length >= 3){
                            for(int i = 1; i < split_positions.size(); ++i){
                                ans.push_back(string_to_int(S.substr(split_positions[i - 1], split_positions[i] - split_positions[i - 1])));
                            }
                        }
                    }
                }
            }
        }
        
        return ans;
    }
};